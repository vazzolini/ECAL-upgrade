// @(#)root/thread:$Id: TThreadPool.h 41756 2011-11-03 16:34:29Z rdm $
// Author: Anar Manafov   20/09/2011

/*************************************************************************
 * Copyright (C) 1995-2011, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifndef ROOT_TThreadPool
#define ROOT_TThreadPool

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// TThreadPool                                                          //
//                                                                      //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

// ROOT
#ifndef ROOT_TObject
#include "TObject.h"
#endif
#ifndef ROOT_TMutex
#include "TMutex.h"
#endif
#ifndef ROOT_TCondition
#include "TCondition.h"
#endif
// STD
#include <queue>
#include <vector>
#include <iostream>
#include <sstream>


//////////////////////////////////////////////////////////////////////////
//                                                                      //
// TNonCopyable                                                         //
// Class which makes child to be non-copyable object.                   //
//                                                                      //
//////////////////////////////////////////////////////////////////////////
class TNonCopyable {
protected:
   TNonCopyable() { }
   ~TNonCopyable() { }
private:
   TNonCopyable(const TNonCopyable&);
   const TNonCopyable& operator=(const TNonCopyable&);
};

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// TThreadPoolTaskImp                                                   //
// A base class for thread pool tasks. Users must inherit their         //
// tasks classes from it.                                               //
// Example:                                                             //
//        class TTestTask: public TThreadPoolTaskImp<TTestTask, int>    //
//                                                                      //
//        in this example,                                              //
//           TTestTask - is a user class, which implements              //
//                       thread pool task object.                       //
//           int - is a type of argument to TTestTask::run method.      //
//                                                                      //
// Please see the tutorial "tutorials/thread/threadPool.C" for          //
// more details on how to use TThreadPool.                              //
//                                                                      //
//////////////////////////////////////////////////////////////////////////
template <class aTask, class aParam>
class TThreadPoolTaskImp {
public:
   bool run(aParam &param) {
      aTask *pThis = reinterpret_cast<aTask *>(this);
      return pThis->runTask(param);
   }
};

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// TThreadPoolTask                                                      //
// This is a supporting class for TThreadPool.                          //
// It wraps users task objects in order to pass tasks arguments in      // 
// type-safe way.                                                       //
//                                                                      //
//////////////////////////////////////////////////////////////////////////
template <class aTask, class aParam>
class TThreadPoolTask {
public:
   typedef TThreadPoolTaskImp<aTask, aParam> task_t;

public:
   TThreadPoolTask(task_t &task, aParam &param):
      fTask(task),
      fTaskParam(param) {
   }
   bool run() {
      return fTask.run(fTaskParam);
   }

private:
   task_t &fTask;
   aParam fTaskParam;
};

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// TThreadPool                                                          //
// This class implement a simple Thread Pool pattern.                   //
// So far it supports only one type of queue - FIFO                     //
//                                                                      //
// Please see the tutorial "tutorials/thread/threadPool.C" for          //
// more details on how to use TThreadPool.                              //
//                                                                      //
//////////////////////////////////////////////////////////////////////////
template <class aTask, class aParam>
class TThreadPool : public TNonCopyable {
    
   typedef TThreadPoolTask<aTask, aParam> task_t;
   typedef std::queue<task_t*>            taskqueue_t;
   typedef std::vector<TThread*>          threads_array_t;

public:
   TThreadPool(size_t threadsCount, bool needDbg = false):
      fStopped(false),
      fSilent(!needDbg) {
      fThreadNeeded = new TCondition(&fMutex);
      fThreadAvailable = new TCondition(&fMutex);

      for (size_t i = 0; i < threadsCount; ++i) {
         TThread *pThread = new TThread(&TThreadPool::Executor, this);
         fThreads.push_back(pThread);
         pThread->Run();
      }

      fThreadJoinHelper = new TThread(&TThreadPool::JoinHelper, this);
   }

   ~TThreadPool() {
      Stop();
      // deleting threads
      threads_array_t::const_iterator iter = fThreads.begin();
      threads_array_t::const_iterator iter_end = fThreads.end();
      for (; iter != iter_end; ++iter)
         delete(*iter);

      delete fThreadJoinHelper;

      delete fThreadNeeded;
      delete fThreadAvailable;
   }

   void PushTask(typename TThreadPoolTask<aTask, aParam>::task_t &task, aParam param) {
      {
         DbgLog("Main thread. Try to push a task");

         TLockGuard lock(&fMutex);
         task_t *t = new task_t(task, param);
         fTasks.push(t);
         ++fTasksCount;

         DbgLog("Main thread. the task is pushed");
      }
      TLockGuard lock(&fMutex);
      fThreadNeeded->Broadcast();
   }

   void Stop(bool processRemainingJobs = false) {
      // prevent more jobs from being added to the queue
      if (fStopped)
         return;

      if (processRemainingJobs) {
         TLockGuard lock(&fMutex);
         // wait for queue to drain
         while (!fTasks.empty() && !fStopped) {
            DbgLog("Main thread is waiting");
            fThreadAvailable->Wait();
            DbgLog("Main thread is DONE waiting");
         }
      }
      // tell all threads to stop
      {
         TLockGuard lock(&fMutex);
         fStopped = true;
         fThreadNeeded->Broadcast();
         DbgLog("Main threads requests to STOP");
      }

      // Waiting for all threads to complete
      fThreadJoinHelper->Run();
      fThreadJoinHelper->Join();
   }

   size_t TasksCount() const {
      return fTasksCount;
   }

   size_t SuccessfulTasks() const {
      return fSuccessfulTasks;
   }

private:
   static void* Executor(void *arg) {
      TThreadPool *pThis = reinterpret_cast<TThreadPool*>(arg);

      while (!pThis->fStopped) {
         task_t *task(NULL);

         std::stringstream ss;
         ss
               << ">>>> Check for tasks."
               << " Number of Tasks: " << pThis->fTasks.size();
         pThis->DbgLog(ss.str());

         // There is a task, let's take it
         {
            TLockGuard lock(&pThis->fMutex);
            // Find a task to perform
            if (pThis->fTasks.empty() && !pThis->fStopped) {
               pThis->DbgLog("waiting for a task");

               // No tasks, we wait for a task to come
               pThis->fThreadNeeded->Wait();

               pThis->DbgLog("done waiting for tasks");
            }

            {
               if (!pThis->fTasks.empty()) {
                  task = pThis->fTasks.front();
                  pThis->fTasks.pop();

                  pThis->DbgLog("get the task");
               }
               pThis->DbgLog("done Check <<<<");
            }
         }

         // Execute the task
         if (task) {
            pThis->DbgLog("Run the task");

            if (task->run()) {
               TLockGuard lock(&pThis->fMutex);
               ++pThis->fSuccessfulTasks;
            }
            delete task;
            task = NULL;

            pThis->DbgLog("Done Running the task");
         }
         // Task is done, report that the thread is free
         TLockGuard lock(&pThis->fMutex);
         pThis->fThreadAvailable->Broadcast();
      }

      pThis->DbgLog("**** DONE ***");
      return NULL;
   }

   static void *JoinHelper(void *arg) {
      TThreadPool *pThis = reinterpret_cast<TThreadPool*>(arg);
      threads_array_t::const_iterator iter = pThis->fThreads.begin();
      threads_array_t::const_iterator iter_end = pThis->fThreads.end();
      for (; iter != iter_end; ++iter)
         (*iter)->Join();

      return NULL;
   }

   static bool IsThreadActive(TThread *pThread) {
      // so far we consider only kRunningState as activity
      return (pThread->GetState() == TThread::kRunningState);
   }

   void DbgLog(const std::string &msg) {
      if (fSilent)
         return;
      TLockGuard lock(&fDbgOutputMutex);
      std::cout << "[" << TThread::SelfId() << "] " << msg << std::endl;
   }

private:
   taskqueue_t     fTasks;
   TMutex          fMutex;
   TCondition     *fThreadNeeded;
   TCondition     *fThreadAvailable;
   threads_array_t fThreads;
   TThread        *fThreadJoinHelper;
   volatile bool   fStopped;
   size_t          fSuccessfulTasks;
   size_t          fTasksCount;
   TMutex          fDbgOutputMutex;
   bool            fSilent; // No DBG messages
};

#endif

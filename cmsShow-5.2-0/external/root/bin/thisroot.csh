# Source this script to set up the ROOT build that this script is part of.
#
# Conveniently an alias like this can be defined in ~/.cshrc:
#   alias thisroot "source bin/thisroot.sh"
#
# This script if for the csh like shells, see thisroot.sh for bash like shells.
#
# Author: Fons Rademakers, 18/8/2006

if ($?ROOTSYS) then
   setenv OLD_ROOTSYS "$ROOTSYS"
endif

# $_ should be source .../thisroot.csh
set ARGS=($_)
set THIS="`dirname ${ARGS[2]}`"
setenv ROOTSYS "`(cd ${THIS}/..;pwd)`"

if ($?OLD_ROOTSYS) then
   setenv PATH `echo $PATH | sed -e "s;:$OLD_ROOTSYS/bin:;:;g" \
                                 -e "s;:$OLD_ROOTSYS/bin;;g"   \
                                 -e "s;$OLD_ROOTSYS/bin:;;g"   \
                                 -e "s;$OLD_ROOTSYS/bin;;g"`
   if ($?LD_LIBRARY_PATH) then
      setenv LD_LIBRARY_PATH `echo $LD_LIBRARY_PATH | \
                             sed -e "s;:$OLD_ROOTSYS/lib:;:;g" \
                                 -e "s;:$OLD_ROOTSYS/lib;;g"   \
                                 -e "s;$OLD_ROOTSYS/lib:;;g"   \
                                 -e "s;$OLD_ROOTSYS/lib;;g"`
   endif
   if ($?DYLD_LIBRARY_PATH) then
      setenv DYLD_LIBRARY_PATH `echo $DYLD_LIBRARY_PATH | \
                             sed -e "s;:$OLD_ROOTSYS/lib:;:;g" \
                                 -e "s;:$OLD_ROOTSYS/lib;;g"   \
                                 -e "s;$OLD_ROOTSYS/lib:;;g"   \
                                 -e "s;$OLD_ROOTSYS/lib;;g"`
   endif
   if ($?SHLIB_PATH) then
      setenv SHLIB_PATH `echo $SHLIB_PATH | \
                             sed -e "s;:$OLD_ROOTSYS/lib:;:;g" \
                                 -e "s;:$OLD_ROOTSYS/lib;;g"   \
                                 -e "s;$OLD_ROOTSYS/lib:;;g"   \
                                 -e "s;$OLD_ROOTSYS/lib;;g"`
   endif
   if ($?LIBPATH) then
      setenv LIBPATH `echo $LIBPATH | \
                             sed -e "s;:$OLD_ROOTSYS/lib:;:;g" \
                                 -e "s;:$OLD_ROOTSYS/lib;;g"   \
                                 -e "s;$OLD_ROOTSYS/lib:;;g"   \
                                 -e "s;$OLD_ROOTSYS/lib;;g"`
   endif
   if ($?PYTHONPATH) then
      setenv PYTHONPATH `echo $PYTHONPATH | \
                             sed -e "s;:$OLD_ROOTSYS/lib:;:;g" \
                                 -e "s;:$OLD_ROOTSYS/lib;;g"   \
                                 -e "s;$OLD_ROOTSYS/lib:;;g"   \
                                 -e "s;$OLD_ROOTSYS/lib;;g"`
   endif
   if ($?MANPATH) then
      setenv MANPATH `echo $MANPATH | \
                             sed -e "s;:$OLD_ROOTSYS/man:;:;g" \
                                 -e "s;:$OLD_ROOTSYS/man;;g"   \
                                 -e "s;$OLD_ROOTSYS/man:;;g"   \
                                 -e "s;$OLD_ROOTSYS/man;;g"`
   endif
endif


if ($?MANPATH) then
# Nothing to do
else
   # Grab the default man path before setting the path to avoid duplicates 
   if ( -X manpath ) then
      set default_manpath = `manpath`
   else
      set default_manpath = `man -w`
   endif
endif

set path = ($ROOTSYS/bin $path)

if ($?LD_LIBRARY_PATH) then
   setenv LD_LIBRARY_PATH $ROOTSYS/lib:$LD_LIBRARY_PATH      # Linux, ELF HP-UX
else
   setenv LD_LIBRARY_PATH $ROOTSYS/lib
endif

if ($?DYLD_LIBRARY_PATH) then
   setenv DYLD_LIBRARY_PATH $ROOTSYS/lib:$DYLD_LIBRARY_PATH  # Mac OS X
else
   setenv DYLD_LIBRARY_PATH $ROOTSYS/lib
endif

if ($?SHLIB_PATH) then
   setenv SHLIB_PATH $ROOTSYS/lib:$SHLIB_PATH                # legacy HP-UX
else
   setenv SHLIB_PATH $ROOTSYS/lib
endif

if ($?LIBPATH) then
   setenv LIBPATH $ROOTSYS/lib:$LIBPATH                      # AIX
else
   setenv LIBPATH $ROOTSYS/lib
endif

if ($?PYTHONPATH) then
   setenv PYTHONPATH $ROOTSYS/lib:$PYTHONPATH
else
   setenv PYTHONPATH $ROOTSYS/lib
endif

if ($?MANPATH) then
   setenv MANPATH `dirname $ROOTSYS/man/man1`:$MANPATH
else
   setenv MANPATH `dirname $ROOTSYS/man/man1`:$default_manpath
endif

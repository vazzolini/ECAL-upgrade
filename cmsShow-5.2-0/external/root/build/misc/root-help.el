;;; root-help.el --- Helper functions for ROOT 
;; -*- mode: emacs-lisp -*- 
;;
;; $Id: root-help.el.in,v 1.1 2002/07/31 20:44:26 rdm Exp $
;;
;;  Emacs lisp functions to help write ROOT based projects
;;  Copyright (C) 2002, 2003 Christian Holm Christensen 
;;
;;  This program is free software; you can redistribute it and/or
;;  modify it under the terms of the GNU General Public License as
;;  published by the Free Software Foundation; either version 2 of the
;;  License, or (at your option) any later version.
;;
;;  This program is distributed in the hope that it will be useful,
;;  but WITHOUT ANY WARRANTY; without even the implied warranty of
;;  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
;;  General Public License for more details.
;;
;;  You should have received a copy of the GNU General Public License
;;  along with this program; if not, write to the Free Software
;;  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
;;  02111-1307 USA
;;
;; Author: Christian Holm Christensen <cholm@nbi.dk>
;; Maintainer: Christian Holm Christensen <cholm@nbi.dk>
;; Created: 20:34:51 Thursday 05/09/02 CEST
;; Version: 1.2
;; Keywords: oop programming
;; 
;;; Commentary:
;;
;;    The Emacs Lisp library `root-help.el' provides a number of
;;    function to ease the development of ROOT based classes and
;;    projects.
;;
;;    I'll bet you, that after using this for a while, you'll never
;;    want to go back to using a normal terminal for running ROOT -
;;    unless you're a Vi-lover of course :-).
;;
;;  Installation
;;   
;;    To use the Emacs Lisp library, download `root-help.el' and put
;;    it somewhere Emacs looks for Lisp libraries.  For people who
;;    have system operator privileges, the following directories are
;;    good candidates:
;;   
;;       /usr/share/emacs/site-lisp
;;       /usr/share/emacs/<version>/site-lisp
;;       /usr/local/share/emacs/site-lisp
;;       /usr/local/share/emacs/<version>/site-lisp
;;       /usr/lib/emacs/site-lisp
;;       /usr/lib/emacs/<version>/site-lisp
;;       /usr/local/lib/emacs/site-lisp
;;       /usr/local/lib/emacs/<version>/site-lisp
;;      
;;    where `<version>' is the version number of the Emacs you're
;;    using.
;;   
;;    For normal users, one should create the directory 
;;
;;       ${HOME}/share/emacs/site-lisp
;;   
;;    And add the line below to `~/.emacs':
;;   
;;       (setq load-path (cons "~/share/emacs/site-lisp" load-path))
;;   
;;    In any case, users that want to use the ROOT Emacs Lisp helper
;;    functions should add the line below to their `~/.emacs':
;;   
;;       (require 'root-help)
;;
;;    System operators may have some way of providing the library
;;    system wide.  For example on Debian systems, one can add the
;;    file `/etc/emacs/site-start.d/50root-help.el' with the contents
;;   
;;       (require 'root-help)
;;   
;;    and the library functions will be available system wide. See
;;    also your Emacs manual for more information.
;;   
;;  Functions
;;   
;;    All the functions in the library are invoked by typing
;;   
;;       M-x <function>
;;   
;;    where `M-x' means "Meta key down and then `x'", where the Meta
;;    key is usually defined to `Alt' and `Esc', and `<function>' is
;;    the function to be invoked.
;;   
;;    No key-bindings have been setup per default, but this is easily
;;    done using the customisation support of Emacs.  Alternatively
;;    one can define key-bindings in ones `~/.emacs' file.  For
;;    example, one could bind the functions in C++ mode like this:
;;
;;       (defun root-c++-mode-hook ()
;;         "Hook for C++ mode - binding ROOT functions"
;;         (define-key c++-mode-map "\C-crc"  'root-class)
;;         (define-key c++-mode-map "\C-crh"  'root-header-skel)
;;         (define-key c++-mode-map "\C-crs"  'root-source-skel)
;;         (define-key c++-mode-map "\C-cri"  'root-include-header)
;;         (define-key c++-mode-map "\C-crm"  'root-main)
;;         (define-key c++-mode-map "\C-crl"  'root-insert-linkdef)
;;         (define-key c++-mode-map "\C-crp"  'root-insert-pragma)
;;         (define-key c++-mode-map "\C-crx"  'root-shell)
;;         (define-key c++-mode-map "\C-crg"  'root-send-line-to-root)
;;         (define-key c++-mode-map "\C-crr"  'root-send-region-to-root)
;;         (define-key c++-mode-map "\C-crb"  'root-send-buffer-to-root)
;;         (define-key c++-mode-map "\C-crf"  'root-execute-file))
;;       (add-hook 'c++-mode-hook 'root-c++-mode-hook)
;;   
;;    root-class [NAME SCOPE INCDIR SRCDIR]  
;; 	Make two new files for a ROOT based class.  All arguments are
;; 	optional, and if not provided, the user will be prompted for
;; 	them.  `NAME' is the name of the class.  This can not be left
;; 	blank.  `SCOPE' the preprocessor scope for header guards, or
;; 	`ROOT' if left blank.  `INCDIR' is where the declaration file
;; 	will live, defaults to current directory.  `SRCDIR' is where
;; 	the definition file will live, defaults to current directory.
;;
;;    root-header-skel [SCOPE BASE DSCR] 
;; 	Insert a skeleton for a ROOT based class The class name is
;; 	derived from the current buffers file name, if possible,
;; 	otherwise the user is prompted for it.  All arguments are
;; 	optional.  If not specified, the user will be prompted for it.
;;
;; 	`SCOPE' is the preprocessor scope for header guards, and
;; 	`BASE' is the possible base class, and `DSCR' a short doc
;;      string 
;;
;;    root-source-skel [SCOPE DSCR]
;; 	Insert a skeleton for a ROOT based class The class name is
;; 	derived from the current buffers file name, if possible,
;; 	otherwise the user is prompted for it.  All arguments are
;; 	optional.  If not specified, the user will be prompted for it.
;;
;; 	`SCOPE' is the preprocessor scope for header guards, and DSCR
;;      a short description
;;
;;    root-include-header [HEADER SCOPE] 
;; 	Insert an `#include' statement with guards for a ROOT class
;;
;; 	`HEADER' is the name of the class to include a header for, and
;; 	`SCOPE' is the optional scope, which defaults to `ROOT'.  If
;; 	not given, `HEADER' is read from the minibuffer with
;; 	completion. The completion is based on the file names found in
;; 	`root-include-directory'.
;;        
;;    root-main
;; 	Insert a skeleton for a ROOT based program Two function will
;; 	be created - one which has the name of the current buffer with
;; 	out extensions, and which the user is to fill in, and a `main'
;; 	function that calls this function.  Like this, we can use the
;; 	file for both interactive input, due to use of guards, and as
;; 	a program.
;;
;; 	The user will be prompted for whether graphics is needed or
;; 	not.  If yes, then a `TApplication' object is created in the
;; 	`main' function.
;;
;;    root-insert-linkdef
;; 	Insert lines appropriate for a linkdef file into current
;; 	buffer
;;
;; 	The user will be prompted for classes to add to the linkdef
;; 	file.  An empty string ends the input.
;;
;;    root-insert-pragma [NAME NEED-PLUS] 
;; 	Insert a pragma linkdef line for a class All arguments are
;; 	optional.  If not given, the user will be prompted for them.
;; 	`NAME' is the name of class, and if `NEED-PLUS' is non-nil, an
;; 	`+' will be appended to the class name line.
;;
;;    root-shell [SCRIPT]
;; 	Start an interactive ROOT session in a buffer The executable
;; 	stored in `root-executable' is executed with the arguments
;; 	`root-executable-args'.  If Emacs is running in a non-graphics
;; 	terminal (like a VT100) `root-executable-args-nographics' is
;; 	passed to the executable.
;;
;;      If the optional [SCRIPT] argument is given, it should be a
;;      file name that will be inserted into the session on startup. 
;;
;;    root-send-line-to-root
;;      Sends the current line to an interactive ROOT session.  If no
;;      session currently exists, one will be created.  The point is
;;      moved down one line, and left in the current window (buffer). 
;;      You can use this to step throught a script.
;;
;;    root-send-region-to-root [START END]
;;      Sends the contents of the current region to an interactive
;;      ROOT session.  If no session exists, then one will be
;;      created.  The point is left in the current window. 
;;
;;    root-send-buffer-to-root
;;      Sends the the current buffer to an interactive ROOT session.  
;;      If no session exists, then one will be created.  The point is
;;      left in the current window.  If the buffer has an associated
;;      file, and it has been modified since the last save, then the
;;      user will be prompted for whether she wants to save the buffer
;;      or not. 
;; 
;;  Customisation
;;   
;;    The library depends on a number of variables that the user may
;;    customise using Emacs' regular customisation support.  All the
;;    customisation is in the sub-group `Root' of the group
;;    `Programming - Tools'
;;   
;;    root-include-directory
;; 	Where the ROOT headers reside.  If the `ROOTSYS' environment
;; 	variable is set, this defaults to `${ROOTSYS}/include',
;; 	otherwise to `/usr/include/root'
;;     
;;    root-executable
;; 	Full path to the ROOT interactive executable. If the `ROOTSYS'
;; 	environment variable is set, this defaults to
;; 	`${ROOTSYS}/bin/root', otherwise to `/usr/bin/root'
;;     
;;    root-executable-args
;; 	Arguments to pass to `root-executable'.  Per default this is
;; 	empty.
;;      
;;    root-executable-args-nographics
;; 	Arguments to pass to `root-executable' in case Emacs is
;; 	running in a non-graphics environment, like a VT100 terminal
;; 	or similar.  Per default this is set to `"-l -b"'
;;
;;    root-execute-file
;;      Execute the current buffer in an interactive ROOT session. 
;;      
;;      If no session exists, then one will be created.  With a prefix
;;      argument, the user is asked to provide a file name.
;;      
;;____________________________________________________________________ 
;;
;;; Code:     

;;____________________________________________________________________
(require 'term)

;;____________________________________________________________________
(defgroup root nil
  "ROOT's Object Oriented Technologies helper functions"
  :group 'programming
  :group 'tools)

;;____________________________________________________________________
(defcustom root-include-directory 
  (if (getenv "ROOTSYS") 
      (concat (getenv "ROOTSYS") "/include")
    "$(ROOTSYS)/include")
  "Where the ROOT headers reside"
  :group 'root)

;;____________________________________________________________________
(defcustom root-executable
  (if (getenv "ROOTSYS") 
      (concat (getenv "ROOTSYS") "/bin/root.exe")
    "$(ROOTSYS)/bin/root.exe")
  "Full path to the ROOT interactive executable"
  :group 'root)

;;____________________________________________________________________
(defcustom root-executable-args ""
  "Arguments passed to the \\[root-executable]"
  :group 'root)

;;____________________________________________________________________
(defcustom root-executable-args-nographics "-l -b"
  "Arguments passed to the \\[root-executable] in non-graphics environment"
  :group 'root)

;;____________________________________________________________________
(defface root-shell-startup-face nil
  "Face to use for the startup text in the root shell"
  :group 'root)
(copy-face 'default 'root-shell-startup-face)
(setq root-shell-startup-face 'root-shell-startup-face) 

;;____________________________________________________________________
(defface root-shell-prompt-face nil
  "Face to use for the prompt in the root shell"
  :group 'root)
(copy-face 'underline 'root-shell-prompt-face)
(setq root-shell-prompt-face 'root-shell-prompt-face)

;;____________________________________________________________________
(defface root-shell-keyword-face nil
  "Face to for keywords in the root shell"
  :group 'root)
(copy-face 'font-lock-keyword-face 'root-shell-keyword-face)
(setq root-shell-keyword-face 'root-shell-keyword-face)

;;____________________________________________________________________
(defface root-shell-warning-face nil
  "Face to for warnings and errors in the root shell"
  :group 'root)
(copy-face 'font-lock-warning-face 'root-shell-warning-face)
(setq root-shell-warning-face 'root-shell-warning-face)

;;____________________________________________________________________
(defface root-shell-string-face nil
  "Face to for strings in the root shell"
  :group 'root)
(copy-face 'font-lock-string-face 'root-shell-string-face)
(setq root-shell-string-face 'root-shell-string-face)

;;____________________________________________________________________
(defface root-shell-constant-face nil
  "Face to for constants in the root shell"
  :group 'root)
(if (string-match "XEmacs\\|Lucid" emacs-version) 
    (copy-face 'default 'root-shell-constant-face)
  (copy-face 'font-lock-constant-face 'root-shell-constant-face))
(setq root-shell-constant-face 'root-shell-constant-face)

;;____________________________________________________________________
(defface root-shell-variable-face nil
  "Face to for variables in the root shell"
  :group 'root)
(copy-face 'font-lock-variable-name-face 'root-shell-variable-face)
(setq root-shell-variable-face 'root-shell-variable-face)

;;____________________________________________________________________
(defface root-shell-function-face nil
  "Face to for functions in the root shell"
  :group 'root)
(copy-face 'font-lock-function-name-face 'root-shell-function-face)
(setq root-shell-function-face 'root-shell-function-face)

;;____________________________________________________________________
(defface root-shell-builtin-face nil
  "Face to for builtins in the root shell"
  :group 'root)
(if (string-match "XEmacs\\|Lucid" emacs-version) 
    (copy-face 'font-lock-keyword-face 'root-shell-builtin-face)
  (copy-face 'font-lock-builtin-face 'root-shell-builtin-face))
(setq root-shell-builtin-face 'root-shell-builtin-face)


;;____________________________________________________________________
(defface root-shell-type-face nil
  "Face to for types in the root shell"
  :group 'root)
(copy-face 'font-lock-type-face 'root-shell-type-face)
(setq root-shell-type-face 'root-shell-type-face)

;;____________________________________________________________________
(defun  root-class    (&optional name scope incdir srcdir dscr) 
  "Make two new files for a ROOT based class. 

All arguments are optional, and if not provided, the user will be
prompted for them.  

NAME is the name of the class.  This can not be left blank.  SCOPE the
preprocessor scope for header guards, or 'ROOT' if left blank.  INCDIR 
is where the declaration file will live, defaults to current
directory.  SRCDIR is where the definition file will live, defaults
to current directory.  DSCR is the short description.

Uses \\[root-header-skel] and \\[root-source-skel]" 
  (interactive)
  ;; Read the class name from the minibuffer is the user didn't supply
  ;; one 
  (while (or (not name) (string= name "")) 
    ;; If that's not possible prompt user for it
    (setq name (read-string "Class name: ")))
  ;; Get the preprocessor scope if not passed by user 
  (if (not scope) (setq scope (read-string "Scope: ")))
  ;; Figure out where to put the declaration file 
  (if (not incdir) 
      (setq incdir (read-string "Declaration directory (.): "))) 
  ;; Set default if user types C-j
  (if (eq (length incdir) 0) (setq incdir "."))
  ;; Figure out where to put the declaration file 
  (if (not srcdir) 
      (setq srcdir (read-string "Implementation directory (.): "))) 
  ;; Set default if user types C-j
  (if (eq (length srcdir) 0) (setq srcdir "."))
  ;; Make file names
  (let ((header-name) (source-name))
    (setq header-name (if (string= "." incdir) (concat name ".h") 
			(concat incdir "/" name ".h")))
    (setq source-name (if (string= "." srcdir) (concat name ".cxx") 
			(concat srcdir "/" name ".cxx"))) 
    ;; Check that files doesn't exist
    (if (file-exists-p header-name) 
	(error "Header file '%s' already exists - will not overwrite" 
	       header-name))
    (if (file-exists-p source-name) 
	(error "Source file '%s' already exists - will not overwrite" 
	       source-name))
    ;; Check files are writeable 
    (if (not (file-writable-p header-name)) 
	(error "Cannot write header file '%s'" header-name))
    (if (not (file-writable-p source-name)) 
	(error "Cannot write source file '%s'" source-name))
    ;; Open the header file and make that current buffer
    (find-file header-name) 
    (c++-mode)
    ;; Write the header skeleton
    (root-header-skel scope)
    ;; Save the file 
    (save-buffer)
    ;; Open the source file and make that current buffer
    (if (not (string= incdir "."))
	(find-file-other-window (concat "../" source-name))
      (find-file-other-window source-name))
    ;; Write the source skeleton
    (root-source-skel scope)
    ;; Save the file 
    (save-buffer)
    ;; Write a message to user
    (message "Class is in '%s' and '%s'" header-name source-name)))

;;____________________________________________________________________
(defun root-header-skel (&optional scope base dscr)
  "Insert a skeleton for a ROOT based class

The class name is derived from the current buffers file name, if
possible, otherwise the user is prompted for it.  All arguments are
optional.  If not specified, the user will be prompted for it.  

SCOPE is the preprocessor scope for header guards, BASE is the
possible base class, and DSCR is a short description of the class" 
  (interactive)
  (let (name)
    ;; Get the class name form the filename of the buffer 
    (setq name (file-name-sans-extension (buffer-name)))
    ;; If that failed, prompt the user for it
    (while (or (not name) (string= name "")) 
      ;; If that's not possible prompt user for it
      (setq name (read-string "Class name: ")))
    ;; If the scope isn't set, 
    (if (or (not scope) (string= "" scope)) (setq scope "ROOT"))
    ;; If the base file isn't set, prompt the user for it. 
    (if (or (not base) (string= "" base)) 
	(setq base (root-read-class "Base class: " "TObject")))
    ;; Get a description string 
    (if (or (not dscr) (string= dscr "")) 
	(setq dscr (read-string "Documentation: " "DOCUMENT ME")))
    ;; Go to the top of the file
    (goto-char (point-min))
    (insert "// -*- mode: c++ -*- \n")
    (root-insert-header-info)
    (insert "#ifndef " scope "_" name "\n#define " scope "_" name "\n")  
    (if (and base (not (string= base ""))) (root-include-header base))
    (insert "\nclass " name)
    (if (and base (not (string= base ""))) (insert " : public " base))
    (insert "
{
private:
public:
  " name "();
  virtual ~" name "() {}

  ClassDef(" name ",0) //" dscr "
};

#endif
")
    (root-insert-bottom-info)
    (goto-char (point-min))))

;;____________________________________________________________________
(defun root-source-skel (&optional scope dscr)
  "Insert a skeleton for a ROOT based class

The class name is derived from the current buffers file name, if
possible, otherwise the user is prompted for it.  All arguments are 
optional.  If not specified, the user will be prompted for it.   

SCOPE is the preprocessor scope for header guards, and DSCR is a
description string."
  (interactive)  
  (let (name)
    ;; Get the class name form the filename of the buffer 
    (setq name (file-name-sans-extension (buffer-name)))
    ;; If that failed, prompt the user for it
    (while (or (not name) (string= name "")) 
      ;; If that's not possible prompt user for it
      (setq name (read-string "Class name: ")))
    ;; If the scope isn't set, 
    (if (or (not scope) (string= "" scope)) (setq scope "ROOT"))
    ;; Get a description string 
    (if (or (not dscr) (string= dscr "")) 
	(setq dscr (read-string "Long description: " "DOCUMENT ME")))
    (goto-char (point-min))
    ;; Insert a skeleton for the class description 
    (insert 
   "//____________________________________________________________________
//
// " dscr "
// 

")
  ;; Insert author, date, copyright information
    (root-insert-header-info)
    ;; Include the class declaration
    (root-include-header name scope)
    ;; Insert a dummy CTOR and class implementation macro 
    (insert "
//____________________________________________________________________
ClassImp(" name ");

//____________________________________________________________________
" name "::" name "()
{
  // Default constructor
}

")
    (root-insert-bottom-info)
    (goto-char (point-min))))

;;____________________________________________________________________
(defun root-insert-header-info () 
  "Inserts some lines for a header, including CVS Id, author, date copyright"
  (insert 
"//____________________________________________________________________ 
//  
// $Id" "$ 
// Author: " (user-full-name)  " <" user-mail-address ">
// Update: " (format-time-string "%Y-%m-%d %T%z") "
// Copyright: " (format-time-string "%Y") " (C) " (user-full-name) "
//
"))

;;____________________________________________________________________
(defun root-insert-bottom-info () 
  "Inserts some lines for a footer"
  (insert 
"//____________________________________________________________________ 
//  
// EOF
//
"))

;;____________________________________________________________________
(defun root-include-header (&optional header scope) 
  "Insert an #include statement with guards for a ROOT class

HEADER is the name of the class to include a header for, and SCOPE is
the optional scope, which defauls to 'ROOT'.  If not given, HEADER is
read from the minibuffer _with_ completion.  The completion is based on
the file names found in \\[root-include-directory]"
  (interactive) 
  ;; Read the class name (with completion) from user if it isn't given
  ;; already 
  (if (not header) (setq header (root-read-class "Class name: " nil)))
  ;; If the scope ins't set, set it to ROOT 
  (if (or (not scope) (string= "" scope)) (setq scope "ROOT"))
  ;; Insert the lines we need 
  (insert "#ifndef " scope "_" header 
	  "\n#include \"" header ".h\"\n#endif\n"))

;;____________________________________________________________________
(defun root-main () 
  "Insert a skeleton for a ROOT based program

Two function will be created - one which has the name of the current
buffer with out extensions, and which the user is to fill in, and a
'main' function that calls this function.  Like this, we can use the
file for both interactive input, due to use of guards, and as a
program. 

The user will be prompted for wether graphics is needed or not.  If
yes, then a TApplication object is created in the main function."
  (interactive) 
  ;; 
  (let (name)
    (setq name (file-name-sans-extension (buffer-name)))
    (setq need-application (y-or-n-p "Do you need graphics "))
    (goto-char (point-min))
    (root-insert-header-info)
    (insert "//\n#ifndef __CINT__\n")
    (if need-application (root-include-header "TApplication"))
    (insert "// PUT HEADERS HERE
#endif

int " name "()
{
  // DEFINE YOUR MAIN FUNCTION HERE

  return 0;
}

#ifndef __CINT__
int main(int argc, char** argv)
{
  ")
    (if need-application  
	;; If we need an application, then we insert, that, store the
	;; return value of the function, run the application, and
	;; return the stored return value. 
	(insert "TApplication " name "App(\"" name "App\", &argc, argv);
  int retVal = " name "();
  " name "App.Run();
  return retVal;")
      ;; Otherwise we just insert the call 
      (insert "return " name "();"))
    ;; Closing brace
    (insert "\n}\n#endif\n\n")
    ;; Bottom of the file 
    (root-insert-bottom-info)
    (goto-char (point-min))))

;;____________________________________________________________________
(defun root-insert-linkdef () 
  "Insert lines appropiate for a linkdef file into current buffer

The user will be prompted for classes to add to the linkdef file.  An
empty string ends the input."
  (interactive)
  (insert "// -*- mode: c++ -*-\n")
  (root-insert-header-info)
  (insert "
#ifndef __CINT__
#error Not for compilation
#endif

#pragma link off all functions;
#pragma link off all globals;
#pragma link off all classes;

")
  ;; Let the user add classes right away 
  (while 
      (progn (setq name (read-string "Add a class: ")) 
	     (> (length name) 0))
    (root-insert-pragma name))
  ;; insert a new line and the end stuff
  (insert "\n")
  (root-insert-bottom-info)
  (goto-char (point-min)))

;;____________________________________________________________________
(defun root-insert-pragma (&optional name need-plus)
  "Insert a pramga linkdef line for a class

All arguments are optional.  If not given, the user will be prompted
for them.  NAME is the name of class, and if NEED-PLUS is non-nil, an
'+' will be appended to the class name line." 
  (interactive)
  ;; Read the class name 
  (while (or (not name) (string= name "")) 
    ;; If that's not possible prompt user for it
    (setq name (read-string "Class name: ")))
  ;; Check if we need a plus or not. 
  (if (not need-plus)  
      (setq need-plus (y-or-n-p "Do you schema evolution ")))
  ;; Insert the actual line 
  (insert "#pragma link C++ class " name)
  ;; insert the plus if we need it.
  (if need-plus (insert "+"))
  ;; and a final newline 
  (insert ";\n"))

;;____________________________________________________________________
(defun root-complete-class (name filter flag) 
  "Completition function for root-read-class.  

It looks up the passed name in the ROOT header directory set by
\\[root-include-directory], and does the matching on files there."
  (if flag 
      ;; Return a list of all possible completions 
      (let (files)
	(setq files 
	      (file-name-all-completions name root-include-directory))
	(if (not files) (error "no matches on '%s'" name))
      (mapcar 'file-name-sans-extension files))
    ;; Returns:
    ;; t if an exact match is found, 
    ;; nil if no possible match is found,  
    ;; completion if unique 
    ;; Longest possible completion if not
    (let (first) 
      (setq first (file-name-completion name root-include-directory))
      (if (and (stringp first) (string= first (concat name ".h"))) 
	  t
	(progn 
	  (if (stringp first)
	      (file-name-sans-extension first)))))))

;;____________________________________________________________________
(defun root-read-class (prompt default)
  "Interactively read the name of a ROOT class.  

Completion is done based  on the file names found in
\\[root-include-directory]" 
  (completing-read prompt 'root-complete-class nil nil default))

;;____________________________________________________________________
(defun sys-include-header (&optional header) 
  "Insert an #include for a system header" 
  (interactive) 
  (if (not header)
      (setq header (read-string "Header name: ")))
  (insert "#ifndef __" (upcase header) "__\n"
          "#include <" (symbol-value 'header) ">\n"
          "#endif\n"))

;;____________________________________________________________________
(defvar root-shell-font-lock-keywords 
  '(("^  \\*+$"                                   . root-shell-startup-face)
    ("^  \\*.*\\*$"                               . root-shell-startup-face)
    ("^Compiled for.*$"                           . root-shell-startup-face)
    ("^CINT/ROOT C/C\\+\\+ .*$"                   . root-shell-startup-face)
    ("^Type \\? for help\\. Commands must be .*$" . root-shell-startup-face)
    ("^Enclose multiple statements.*$"            . root-shell-startup-face)
    ("^FreeType Engine .* used to render.*$"      . root-shell-startup-face)
    ("root \\[[0-9]+\\]"                          . root-shell-prompt-face)
    ("Root *>"                                    . root-shell-prompt-face)
    ("end with '.'[^>]*>"                         . root-shell-prompt-face)
    ("^ *\\*+ Interpreter error recovered \\*+$"  . root-shell-warning-face)
    ("^ *\\*+ Break \\*+ "                        . root-shell-warning-face)
    ("^\\(Sys\\)?Error"                           . root-shell-warning-face)
    ("^Warning"                                   . root-shell-warning-face)
    ("^Fatal"                                     . root-shell-warning-face)
    ("\"[^\"]*\""                                 . root-shell-string-face)
    ("0[xX][0-9A-Fa-f]+"                          . root-shell-constant-face)
    ("[+-]?[0-9]+\\.?[0-9]*[eE][+-]?[0-9]+[lL]?"  . root-shell-constant-face)
    ("[+-]?[0-9]*\\.[0-9]+[eE][+-]?[0-9]+[lL]?"   . root-shell-constant-face)
    ("\\b[+-]?[0-9]+\\.?[0-9]*[uUlL]?\\b"         . root-shell-constant-face)
    ("\\b[+-]?[0-9]*\\.[0-9][uUlL]?\\b"           . root-shell-constant-face)
    ("\\(//.*\\|/\\*.*\\*/\\)"                    . root-shell-comment-face)
    ("\(\\sw+\\s-*\)("                            . root-shell-function-face)
    ("\\b\\sw+_t\\b"                              . root-shell-type-face)
    ("\\(T[A-Z]\\sw+\\|E[A-Z]\\sw+\\)"            . root-shell-type-face)
    ("\\b\\(const_\\)?iterator\\b"                . root-shell-type-face) 
    ("\\b\\([io]+\\|[io]?[f]\\)stream\\b"         . root-shell-type-face)
    ("\\b[io]?strstream\\b"                       . root-shell-type-face)
    ("\\b\\(if\\|else\\|for\\|while\\|do\\)\\b"   . root-shell-keyword-face)
    ("\\b\\(case\\|switch\\)\\b"                  . root-shell-keyword-face)
    ("\\b\\(typedef\\|typename\\|typeid\\)\\b"    . root-shell-keyword-face)
    ("\\b\\(class\\|struct\\)\\b"                 . root-shell-keyword-face)
    ("\\b\\(new\\|delete\\|sizeof\\)\\b"          . root-shell-keyword-face)
    ("\\b\\(register\\|static\\|mutable\\)\\b"    . root-shell-keyword-face)
    ("\\b\\(volatile\\|const\\)\\b"               . root-shell-keyword-face)
    ("\\b\\(private\\|protected\\|public\\)\\b"   . root-shell-keyword-face)
    ("\\b\\(cout\\|cerr\\|cin\\|endl\\)\\b"       . root-shell-variable-face)
    ("\\b\\(flush\\|setw\\|setprecision\\)\\b"    . root-shell-variable-face)
    ("\\b\\(gROOT\\|gStyle\\)\\b"                 . root-shell-variable-face)
    ("\\b\\(gApplication\\|gPad\\)\\b"            . root-shell-variable-face)
    ("\\b\\(int\\|short\\|long\\|unsigned\\)\\b"  . root-shell-type-face)
    ("\\b\\(float\\|double\\|char\\)\\b"          . root-shell-type-face)
    ("\\b\\(map\\|vector\\|list\\|multimap\\)\\b" . root-shell-type-face) 
    ("\\b\\(string\\|complex\\|streambuf\\)\\b"   . root-shell-type-face) 
    ("\\b\\(exception\\|runtime_error\\)\\b"      . root-shell-type-face) 
    ("\\.\\S-+"                                   . root-shell-builtin-face)
    )
  "Additional expressions to highlight in ROOT intaractive mode.")
;;____________________________________________________________________
(defconst root-name "ROOT" 
  "The name of ROOT")

;;____________________________________________________________________
(defconst root-shell-buffer (concat "*" root-name "*")
  "The name of the root-shell buffer")

;;____________________________________________________________________
(defun root-shell-histo (dimension type) 
  "Make a histogram in the interactive shell"
  (interactive (list 
		(let ((d 0))
		  (while (<= d 0)
		    (setq d (string-to-int (read-string "Dimension: ")))) d) 
		(read-char "Type: ")))
  (let ((type (format "TH%d%c" dimension (upcase type)))
	(name "h")
	(command nil))
    (while (progn 
	     (setq name (read-string "Name: " name))
	     (string= name "")))
    (setq command (concat type "* " name " = new " type "(\"" name "\",\""))
    (setq command (concat command (read-string "Title: " ) "\","))
    (dotimes (i dimension)
      (let ((bins "") (low "") (high ""))
	(setq axis (cond ((= i 0) "X") ((= i 1) "Y") ((= i 2) "Z")))
	(while 
	    (progn
	      (setq bins (read-string (concat "# of " axis " bins: ")))
	      (<= (string-to-int bins) 0)))
	(setq command (concat command bins ","))
	(setq low (read-string (concat axis " minimum: ")))
	  (setq command (concat command low ","))
	  (while 
	      (progn
		(setq high (read-string (concat axis " maximum: ")))
		(> (string-to-int low) (string-to-int high))))
	  (setq command (concat command high 
				(cond ((= (1+ i) dimension) ")") (t ","))))))
    (root-shell-paste (concat command ";\n") nil)))

;;____________________________________________________________________
(defun root-shell-histo-1c () "" (interactive) (root-shell-histo 1 ?C))
(defun root-shell-histo-1s () "" (interactive) (root-shell-histo 1 ?S))
(defun root-shell-histo-1f () "" (interactive) (root-shell-histo 1 ?F))
(defun root-shell-histo-1d () "" (interactive) (root-shell-histo 1 ?D))
(defun root-shell-histo-1k () "" (interactive) (root-shell-histo 1 ?K))

;;____________________________________________________________________
(defun root-shell-histo-2c () "" (interactive) (root-shell-histo 2 ?C))
(defun root-shell-histo-2s () "" (interactive) (root-shell-histo 2 ?S))
(defun root-shell-histo-2f () "" (interactive) (root-shell-histo 2 ?F))
(defun root-shell-histo-2d () "" (interactive) (root-shell-histo 2 ?D))
(defun root-shell-histo-2k () "" (interactive) (root-shell-histo 2 ?K))

;;____________________________________________________________________
(defun root-shell-histo-3c () "" (interactive) (root-shell-histo 3 ?C))
(defun root-shell-histo-3s () "" (interactive) (root-shell-histo 3 ?S))
(defun root-shell-histo-3f () "" (interactive) (root-shell-histo 3 ?F))
(defun root-shell-histo-3d () "" (interactive) (root-shell-histo 3 ?D))
(defun root-shell-histo-3k () "" (interactive) (root-shell-histo 3 ?K))

;;____________________________________________________________________
(defun root-shell-browser () "" (interactive) 
  (root-shell-paste "TBrowser* b = new TBrowser(\"b\", \"Browser\");\n" nil))

;;____________________________________________________________________
(defun root-shell-canvas () "" (interactive) 
  (root-shell-paste "TCanvas* c = new TCanvas(\"c\", \"Canvas\");\n" nil))

;;____________________________________________________________________
(defun root-shell-file (&optional file mode) 
  "" 
  (interactive) 
  (if (or (not file) (string= "file"))
      (progn  
	(setq file (read-file-name "File to open: "))
	(if (and file (not (file-directory-p file)))
	    (setq file (expand-file-name file))
	  (error "No file to open"))))
  (if (not (file-exists-p file)) (setq mode "RECREATE"))
  (if (not mode) (setq mode (read-string "How to open the file: " "READ")))
  (root-shell-paste (concat "TFile* file = TFile::Open(\"" file 
			    "\",\"" mode "\");\n") nil))


;;____________________________________________________________________
(defun root-shell-command (command &optional arg file yn) 
  "" 
  (let ((command (concat "." command))) 
    (if arg 
	(if file 
	    (progn  
	      (setq file (read-file-name arg))
	      (if (and file (not (file-directory-p file)))
		  (setq file (expand-file-name file))
		(error "No file argument given to %s" command))
	      (setq command (concat command " " file)))
	  (if yn 
	      (if (y-or-n-p (concat "Turn on " arg " ")) 
		  (setq command (concat command " 1"))
		(setq command (concat command " 0"))))
	  (setq command (concat command " "(read-string arg)))))
    (root-shell-paste (concat command "\n") nil)))
(defun root-shell-redirect-output () ""
  (interactive) (root-shell-command ">" "Output file: " t))
(defun root-shell-redirect-error () ""
  (interactive) (root-shell-command "2>" "Error file: " t))
(defun root-shell-redirect-both () ""
  (interactive) (root-shell-command ">&" "File: " t))
(defun root-shell-help () ""
  (interactive) (root-shell-command "help"))
(defun root-shell-help-search () ""
  (interactive) (root-shell-command "/" "Keyword: "))
(defun root-shell-shell () ""
  (interactive) (root-shell-command "!" "Shell command: "))
(defun root-shell-view () ""
  (interactive) (root-shell-command "v" "Line: "))
(defun root-shell-view-stack () ""
  (interactive) (root-shell-command "V" "Line: "))
(defun root-shell-trace () ""
  (interactive) (root-shell-command "t"))
(defun root-shell-debug-file () ""
  (interactive) (root-shell-command "f" "File: " t))
(defun root-shell-toggle-trace () ""
  (interactive) (root-shell-command "T"))
(defun root-shell-toggle-auto () ""
  (interactive) (root-shell-command "A" "automatic variables" nil t))
(defun root-shell-trace-class () ""
  (interactive) (root-shell-command "trace" "Class: "))
(defun root-shell-untrace-class () ""
  (interactive) (root-shell-command "deltrace" "Class: "))
(defun root-shell-print-expr () ""
  (interactive) (root-shell-command "p" "Expression: "))
(defun root-shell-step-expr () ""
  (interactive) (root-shell-command "s" "Expression: "))
(defun root-shell-step-over-expr () ""
  (interactive) (root-shell-command "S" "Expression: "))
(defun root-shell-exec-file () ""
  (interactive) (root-shell-command "x" "File: " t))
(defun root-shell-exec-filefunc () ""
  (interactive) (root-shell-command "X" "File: " t))
(defun root-shell-edit () ""
  (interactive) (root-shell-command "E" "File (optional): " t))
(defun root-shell-load () ""
  (interactive) (root-shell-command "L" "File: " t))
(defun root-shell-reload () ""
  (interactive) (root-shell-command "La" "File: " t))
(defun root-shell-unload () ""
  (interactive) (root-shell-command "U" "File: " t))
(defun root-shell-toggle-copy () ""
  (interactive) (root-shell-command "C" "copy to temporary directory" nil t))
(defun root-shell-undo () ""
  (interactive) (root-shell-command "undo"))
(defun root-shell-lang () ""
  (interactive) (root-shell-command "lang"))
(defun root-shell-global () ""
  (interactive) (root-shell-command "g" "Global variable (empty for all): "))
(defun root-shell-local () ""
  (interactive) (root-shell-command "l" "Local Variable (empty for all): "))
(defun root-shell-class () ""
  (interactive) (root-shell-command "class" "Class (empty for all): "))
(defun root-shell-class-all () ""
  (interactive) (root-shell-command "Class" "Class (empty for all): "))
(defun root-shell-typedef () ""
  (interactive) (root-shell-command "typedef" "Type (empty for all): "))
(defun root-shell-function () ""
  (interactive) (root-shell-command "function"))
(defun root-shell-macro () ""
  (interactive) (root-shell-command "macro"))
(defun root-shell-template () ""
  (interactive) (root-shell-command "template"))
(defun root-shell-include () ""
  (interactive) (root-shell-command "include"))
(defun root-shell-files () ""
  (interactive) (root-shell-command "file"))
(defun root-shell-where () ""
  (interactive) (root-shell-command "where"))
(defun root-shell-security () ""
  (interactive) (root-shell-command "security"))
(defun root-shell-refcount () ""
  (interactive) (root-shell-command "refcount"))
(defun root-shell-garbage () ""
  (interactive) (root-shell-command "garbage"))
(defun root-shell-do-garbage () ""
  (interactive) (root-shell-command "Garbage"))
(defun root-shell-cover () ""
  (interactive) (root-shell-command "cover" "File: " t))
(defun root-shell-return () ""
  (interactive) (root-shell-command "return" "Value: "))
(defun root-shell-ignore () ""
  (interactive) (root-shell-command "i"))
(defun root-shell-continue () ""
  (interactive) (root-shell-command "c" "Line (optional): "))
(defun root-shell-step-out () ""
  (interactive) (root-shell-command "e"))
(defun root-shell-break () ""
  (interactive) (root-shell-command "break" "Line: "))
(defun root-shell-del-break () ""
  (interactive) (root-shell-command "db" "Line: "))
(defun root-shell-assert () ""
  (interactive) (root-shell-command "a" "Expression (blank to turn off): "))
(defun root-shell-optimization () ""
  (interactive) (root-shell-command "O" "Level [0-4]: "))
(defun root-shell-toggle-debug () ""
  (interactive) (root-shell-command "debug"))
(defun root-shell-toggle-disassembler () ""
  (interactive) (root-shell-command "dasm"))
(defun root-shell-quit () ""
  (interactive) (root-shell-command "q"))
(defun root-shell-force-quit () ""
  (interactive) (root-shell-command "qqq"))
(defun root-shell-save () ""
  (interactive) (root-shell-command "save"))

	    
;;____________________________________________________________________
(defvar root-shell-mode-map nil   "Mode map for \\[root-shell-mode]")
(defun root-shell-mode-make-map () 
  "Defines the keymap.  This _must_ be called after \\[term-char-mode], 
otherwise, the parent mode \\[term-raw-map] is not defined yet, hence 
this function"
  (cond 
   ((not root-shell-mode-map)
    (let (map menumap menumap-top)
      ;; Top-level keymap
      (if (string-match "XEmacs\\|Lucid" emacs-version)
	  (progn 
	    (set-keymap-parents map (list term-raw-map))
	    (set-keymap-name map 'root-shell-mode-map))
	(setq map (nconc (make-sparse-keymap) term-raw-map)))

      (define-key map "\C-crh" 'root-shell-histo)
      (define-key map "\C-crb" 'root-shell-browser)
      (define-key map "\C-crc" 'root-shell-canvas)
      (define-key map "\C-crx" 'root-shell-script)
      (define-key map "\C-crf" 'root-shell-file)

      ;; ROOT menu map
      (setq menumap-top (make-sparse-keymap "ROOT"))

      ;; Misc menu
      (setq menumap (make-sparse-keymap "Miscellaneous"))
      (define-key menumap [root-shell-save] 
        '("Emergency save" . root-shell-save))
      (define-key menumap [root-shell-force-quit] 
        '("Forced quit" . root-shell-force-quit))
      (define-key menumap [root-shell-quit] 
        '("Quit" . root-shell-quit))
      (define-key menumap [seperator2] '("--"))
      (define-key menumap [root-shell-toggle-auto] 
        '("Toggle automatic variables" . root-shell-toggle-auto))
      (define-key menumap [root-shell-shell]  
	'("Shell command..." . root-shell-shell))
      (define-key menumap [seperator1] '("--"))
      (define-key menumap [root-shell-help-search] 
	'("Help search..." . root-shell-help-search))
      (define-key menumap [root-shell-help] '("Help" . root-shell-help))
      (define-key menumap [seperator0] '("--"))
      (define-key menumap [root-shell-undo] 
        '("Undo previous declarations" . root-shell-undo))
      (define-key menumap-top [misc] (cons "Miscellaneous" menumap))

      ;; Redirection menu
      (setq menumap (make-sparse-keymap "Redirections"))
      (define-key menumap [root-shell-redirect-both] 
        '("Redirect output and error..." . root-shell-redirect-both))
      (define-key menumap [root-shell-redirect-error] 
        '("Redirect error..." . root-shell-redirect-error))
      (define-key menumap [root-shell-redirect-output] 
        '("Redirect output..." . root-shell-redirect-output))
      (define-key menumap-top [redirections] (cons "Redirections" menumap))
      
      ;; Bytecode menu
      (setq menumap (make-sparse-keymap "Byte code"))
      (define-key menumap [root-shell-optimization] 
        '("Set optimization..." . root-shell-optimization))
      (define-key menumap [root-shell-toggle-debug] 
        '("Toggle bytecode display" . root-shell-toggle-debug))
      (define-key menumap [root-shell-toggle-disassembler] 
        '("Toggle disassembler" . root-shell-toggle-disassembler))
      (define-key menumap-top [garbage] (cons "Byte code" menumap))

      ;; Garbage menu
      (setq menumap (make-sparse-keymap "Garbage collection"))
      (define-key menumap [root-shell-refcount] 
        '("Toggle reference counting" . root-shell-refcount))
      (define-key menumap [root-shell-do-garbage] 
        '("Do garbage collection" . root-shell-do-garbage))
      (define-key menumap [root-shell-garbage] 
        '("Show garbage" . root-shell-garbage))
      (define-key menumap-top [garbage] (cons "Garbage Collection" menumap))

      ;; Inspect menu
      (setq menumap (make-sparse-keymap "Inspect"))
      (define-key menumap [root-shell-lang]  
	'("Show Language" . root-shell-lang))
      (define-key menumap [root-shell-security] 
        '("Show security level" . root-shell-security))
      (define-key menumap [root-shell-where] 
        '("Show file position" . root-shell-where))
      (define-key menumap [root-shell-file] 
        '("Show loaded files" . root-shell-files))
      (define-key menumap [root-shell-include] 
        '("Show include include path" . root-shell-include))
      (define-key menumap [root-shell-template] 
        '("Show templates" . root-shell-template))
      (define-key menumap [root-shell-macro] 
        '("Show macros" . root-shell-macro))
      (define-key menumap [root-shell-function] 
        '("Show functions" . root-shell-function))
      (define-key menumap [root-shell-typedef] 
        '("Show typedef..." . root-shell-typedef))
      (define-key menumap [root-shell-class-all] 
        '("Show Class (all-levels)..." . root-shell-class-all))
      (define-key menumap [root-shell-class] 
        '("Show Class..." . root-shell-class))
      (define-key menumap [root-shell-local] 
        '("Show local variable..." . root-shell-local))
      (define-key menumap [root-shell-global]  
	'("Show global variable..." . root-shell-global))
      (define-key menumap-top [inpect] (cons "Inspect" menumap))

      ;; Stack menu
      (setq menumap (make-sparse-keymap "Stack"))
      (define-key menumap [root-shell-cover] 
        '("Save trace coverage..." . root-shell-cover))
      (define-key menumap [root-shell-untrace-class] 
        '("Don't Trace class..." . root-shell-untrace-class))
      (define-key menumap [root-shell-trace-class] 
        '("Trace class..." . root-shell-trace-class))
      (define-key menumap [root-shell-trace] 
        '("Trace function call stack" . root-shell-trace))
      (define-key menumap [root-shell-view-stack] 
        '("View stack around..." . root-shell-view-stack))
      (define-key menumap [root-shell-view] 
	'("View around..." . root-shell-view))
      (define-key menumap [root-shell-toggle-trace] 
        '("Toggle trace mode" . root-shell-toggle-trace))
      (define-key menumap-top [stack] (cons "Stack" menumap))

      ;; Debug menu
      (setq menumap (make-sparse-keymap "Debug"))
      (define-key menumap [root-shell-assert] 
        '("Assert ..." . root-shell-assert))
      (define-key menumap [root-shell-del-break] 
        '("Delete breakpoint..." . root-shell-del-break))
      (define-key menumap [root-shell-break] 
        '("Set breakpoint..." . root-shell-break))
      (define-key menumap [root-shell-return] 
        '("Return..." . root-shell-return))
      (define-key menumap [root-shell-continue] 
        '("Continue to line..." . root-shell-continue))
      (define-key menumap [root-shell-ignore] 
        '("Ignore statement" . root-shell-ignore))
      (define-key menumap [root-shell-step-out] 
        '("Step out from function" . root-shell-step-out))
      (define-key menumap [root-shell-step-over-expr] 
        '("Step over expression..." . root-shell-step-over-expr))
      (define-key menumap [root-shell-step-expr] 
        '("Step into expression..." . root-shell-step-expr))
      (define-key menumap [root-shell-print-expr] 
        '("Print expression..." . root-shell-print-expr))
      (define-key menumap [root-shell-debug-file] 
        '("Set file to debug..." . root-shell-debug-file))
      (define-key menumap-top [debug] (cons "Debug" menumap))

      ;; Load menu
      (setq menumap (make-sparse-keymap "Files"))
      (define-key menumap [root-shell-exec-file] 
        '("Execute statements in file..." . root-shell-exec-file))
      (define-key menumap [root-shell-exec-filefunc] 
        '("Execute function in file..." . root-shell-exec-filefunc))
      (define-key menumap [root-shell-edit] 
	'("Edit file..." . root-shell-edit))
      (define-key menumap [root-shell-load] 
	'("Load file..." . root-shell-load))
      (define-key menumap [root-shell-reload] 
        '("Reload all files after file..." . root-shell-reload))
      (define-key menumap [root-shell-unload] 
        '("Unload file..." . root-shell-unload))
      (define-key menumap [root-shell-toggle-copy] 
        '("Toggle copy to temporary" . root-shell-toggle-copy))
      (define-key menumap-top [files] (cons "Files" menumap))


      (define-key menumap-top [seperator1] '("--"))

      ;; Sub-menu 3D histograms 
      (setq menumap (make-sparse-keymap "3D histograms"))
      (define-key menumap [root-shell-histo-3d] 
	'("TH3D..." . root-shell-histo-3d))
      (define-key menumap [root-shell-histo-3f] 
	'("TH3F..." . root-shell-histo-3f))
      (define-key menumap [root-shell-histo-3s] 
	'("TH3S..." . root-shell-histo-3s))
      (define-key menumap [root-shell-histo-3c] 
	'("TH3C..." . root-shell-histo-3c))
      (define-key menumap [root-shell-histo-3k] 
	'("TH3K..." . root-shell-histo-3k))
      (define-key menumap-top [h3] (cons "3D Histograms" menumap))
      
      ;; Sub-menu 2D histograms 
      (setq menumap (make-sparse-keymap "2D histograms"))
      (define-key menumap [root-shell-histo-2d] 
	'("TH2D..." . root-shell-histo-2d))
      (define-key menumap [root-shell-histo-2f] 
	'("TH2F..." . root-shell-histo-2f))
      (define-key menumap [root-shell-histo-2s] 
	'("TH2S..." . root-shell-histo-2s))
      (define-key menumap [root-shell-histo-2c] 
	'("TH2C..." . root-shell-histo-2c))
      (define-key menumap [root-shell-histo-2k] 
	'("TH2K..." . root-shell-histo-2k))
      (define-key menumap-top [h2] (cons "2D Histograms" menumap))
      
      ;; Sub-menu 1D histograms 
      (setq menumap (make-sparse-keymap "1D histograms"))
      (define-key menumap [root-shell-histo-1d] 
	'("TH1D..." . root-shell-histo-1d))
      (define-key menumap [root-shell-histo-1f] 
      '("TH1F..." . root-shell-histo-1f))
      (define-key menumap [root-shell-histo-1s] 
	'("TH1S..." . root-shell-histo-1s))
      (define-key menumap [root-shell-histo-1c] 
	'("TH1C..." . root-shell-histo-1c))
      (define-key menumap [root-shell-histo-1k] 
	'("TH1K..." . root-shell-histo-1k))
      (define-key menumap-top [h1] (cons "1D Histograms" menumap))
      
      (define-key menumap-top [seperator0] '("--"))

      ;; Menu entries
      (define-key menumap-top [root-shell-browser] 
	'("Browser" . root-shell-browser))
      (define-key menumap-top [root-shell-canvas] 
	'("Canvas" . root-shell-canvas))
      (define-key menumap-top [root-shell-file] 
	'("File..." . root-shell-file))
      (define-key menumap-top [root-shell-script] 
	'("Script..." . root-shell-script))
      
      (define-key map [menu-bar root] (cons "ROOT" menumap-top))
      
      (setq root-shell-mode-map map)))))

;;___________________________________________________________________
(defun root-shell-mode () 
  "Major mode for a ROOT interactive shell

This uses the \\[term-mode] to do most stuff.  Key bindings are as in
that mode.  Extra syntax highlighting is performend."
  (interactive)
  (term-mode)
  (term-char-mode)
  (setq major-mode 'root-shell-mode)
  (setq mode-name root-name)
  (root-shell-mode-make-map)
  (use-local-map root-shell-mode-map)
  (force-mode-line-update)
  (make-local-variable 'font-lock-defaults)
  (setq font-lock-defaults '(root-shell-font-lock-keywords)))
  
;;____________________________________________________________________
(defun root-shell-exec (&optional script switch switchback)
  "Executes ROOT in a buffer if it doesn't exists.  

Always sets the current edit buffer to the *ROOT* buffer. The optional
SCRIPT argument should be a file name"
  (if (term-check-proc root-shell-buffer) 
      (let ((proc (get-buffer-process root-shell-buffer)))
	(set-buffer root-shell-buffer)
	(cond (script
	       (goto-char (point-max))
	       (insert-file-contents script)
	       (setq script (buffer-substring (point-min) (point-max)))
	       (delete-region (point-min) (point-max))
	       (term-send-string proc script))))
    (let* ((args)) 
      (setq args (if (not window-system) 
		     root-executable-args-nographics 
		   root-executable-args))
      (set-buffer (make-term root-name root-executable script args))
      (root-shell-mode)))
  (if switch
      (let ((window (selected-window)))
	(switch-to-buffer-other-window root-shell-buffer)
	(if switchback
	    (select-window window)))))


;;____________________________________________________________________
(defun root-shell-paste (&optional script switch)
  "Make sure a ROOT process is running,and then paste string into process"
  (root-shell-exec nil switch t) 
  (let ((proc (get-buffer-process root-shell-buffer)))
    (set-buffer root-shell-buffer)
    (cond (script 
	   ;; (sleep-for 1) 
	   (goto-char (point-max))
	   (term-send-string proc script)))))
  
;;____________________________________________________________________
(defun root-shell (&optional script)
  "Start an interactive ROOT session in a buffer

The executable stored in \\[root-executable] is executed with the 
arguments \\[root-executable-args].  If Emacs is running in a 
non-graphics terminal (like a VT100) \\[root-executable-args-nographics]
is passed to the executable

If the optional SCRIPT argument is given, it should be a file name
that will be inserted into the session on startup."  
  (interactive)
  (if (term-check-proc root-shell-buffer) 
      (root-shell-paste script t)
    (root-shell-exec script t nil)))

;;____________________________________________________________________
(defun root-send-buffer-to-root () 
  "Sends the the current buffer to an interactive ROOT session.  

If no session exists, then one will be created.  The point is
left in the current window.  If the buffer has an associated
file, and it has been modified since the last save, then the
user will be prompted for whether she wants to save the buffer
or not. "
  (interactive) 
  (let ((file (buffer-file-name))
	(tmp-file nil))
    (save-excursion 
      (if file 
	  (if (buffer-modified-p) 
	      (if (y-or-n-p "Save current buffer? ") (save-buffer))))
      (root-shell-paste (buffer-substring (point-min) (point-max)) t))))

;;____________________________________________________________________
(defun root-send-region-to-root (&optional start end) 
  "Sends the contents of the current region to an interactive ROOT session.

If no session exists, then one will be created.  The point is left in
the current window."
  (interactive "r") 
  (root-shell-paste (buffer-substring (region-beginning) (region-end)) t))

;;____________________________________________________________________
(defun root-send-line-to-root () 
  "Sends the current line to an interactive ROOT session.  

If no session currently exists, one will be created.  The point is 
moved down one line, and left in the current window (buffer). 
You can use this to step throught a script."
  (interactive) 
  (let ((beg (point)))
    (forward-line 1) (root-shell-paste (buffer-substring beg (point)) t)))

;;____________________________________________________________________
(defun  root-shell-script (prefix) 
  "Execute the current buffer in an interactive ROOT session.

If no session exists, then one will be created.  With a prefix
argument, the user is asked to provide a file name." 
  (interactive "P") 
  (let ((file (buffer-file-name)))
    (if (or (not file) prefix) 
	(setq file (expand-file-name 
		    (read-file-name "File to execute: " nil nil t))))
    (if (and file (not (file-directory-p file)))
	(setq file (expand-file-name file))
      (error "No file to execute"))
    (if (and (buffer-file-name) 
	     (string= file (expand-file-name (buffer-file-name)))
	     (buffer-modified-p))
	(if (y-or-n-p "Save current buffer? ")
	    (save-buffer)))
    (root-shell-paste (concat ".x " file "\n")) t))
(defun root-execute-file (prefix) "" (root-shell-script prefix))

;;____________________________________________________________________
;; Identify this package	  
(provide 'root-help)

;;____________________________________________________________________
;;
;;; root-help.el ends here
;;

if ( -d /opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/bin-real ) then
  if ( ${?PATH} ) then
    setenv PATH "/opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/bin-real:$PATH"
  else
    setenv PATH "/opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/bin-real"
  endif
endif
if ( -f /opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/etc/profile.d/dependencies-setup.csh ) source /opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/etc/profile.d/dependencies-setup.csh; endif
set GCC_ROOT="/opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2"
set GCC_VERSION="4.6.2"
set GCC_REVISION="1"
set GCC_CATEGORY="external"
if ( -d /opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/bin ) then
  if ( ${?PATH} ) then
    setenv PATH "/opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/bin:$PATH"
  else
    setenv PATH "/opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/bin"
  endif
endif
if ( -d /opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/lib ) then
  if ( ${?DYLD_FALLBACK_LIBRARY_PATH} ) then
    setenv DYLD_FALLBACK_LIBRARY_PATH "/opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/lib:$DYLD_FALLBACK_LIBRARY_PATH"
  else
    setenv DYLD_FALLBACK_LIBRARY_PATH "/opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/lib"
  endif
endif
if ( -d /opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/lib64 ) then
  if ( ${?LD_LIBRARY_PATH} ) then
    setenv LD_LIBRARY_PATH "/opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/lib64:$LD_LIBRARY_PATH"
  else
    setenv LD_LIBRARY_PATH "/opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/lib64"
  endif
endif


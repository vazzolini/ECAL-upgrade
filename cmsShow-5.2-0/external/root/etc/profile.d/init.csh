if ( -f /opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4/etc/profile.d/dependencies-setup.csh ) source /opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4/etc/profile.d/dependencies-setup.csh; endif
set ROOT_ROOT="/opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4"
set ROOT_VERSION="5.32.00-cms4"
set ROOT_REVISION="1"
set ROOT_CATEGORY="lcg"
if ( -d /opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4/bin ) then
  if ( ${?PATH} ) then
    setenv PATH "/opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4/bin:$PATH"
  else
    setenv PATH "/opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4/bin"
  endif
endif
if ( -d /opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4/lib ) then
  if ( ${?DYLD_FALLBACK_LIBRARY_PATH} ) then
    setenv DYLD_FALLBACK_LIBRARY_PATH "/opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4/lib:$DYLD_FALLBACK_LIBRARY_PATH"
  else
    setenv DYLD_FALLBACK_LIBRARY_PATH "/opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4/lib"
  endif
endif
if ( -d /opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4/lib/python ) then
  if ( ${?PYTHONPATH} ) then
    setenv PYTHONPATH "/opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4/lib/python:$PYTHONPATH"
  else
    setenv PYTHONPATH "/opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4/lib/python"
  endif
endif
setenv ROOTSYS "/opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4"


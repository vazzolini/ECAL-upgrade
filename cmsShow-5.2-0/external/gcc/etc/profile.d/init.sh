[ ! -d /opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/bin-real ] || export PATH="/opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/bin-real${PATH:+:$PATH}";
if [ -f /opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/etc/profile.d/dependencies-setup.sh ]; then . /opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/etc/profile.d/dependencies-setup.sh; fi
GCC_ROOT="/opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2"
GCC_VERSION="4.6.2"
GCC_REVISION="1"
GCC_CATEGORY="external"
[ ! -d /opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/bin ] || export PATH="/opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/bin${PATH:+:$PATH}";
[ ! -d /opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/lib ] || export DYLD_FALLBACK_LIBRARY_PATH="/opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/lib${DYLD_FALLBACK_LIBRARY_PATH:+:$DYLD_FALLBACK_LIBRARY_PATH}";
[ ! -d /opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/lib64 ] || export LD_LIBRARY_PATH="/opt/alja/cmssw-462/osx106_amd64_gcc462/external/gcc/4.6.2/lib64${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}";


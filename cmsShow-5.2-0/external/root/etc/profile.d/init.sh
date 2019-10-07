if [ -f /opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4/etc/profile.d/dependencies-setup.sh ]; then . /opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4/etc/profile.d/dependencies-setup.sh; fi
ROOT_ROOT="/opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4"
ROOT_VERSION="5.32.00-cms4"
ROOT_REVISION="1"
ROOT_CATEGORY="lcg"
[ ! -d /opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4/bin ] || export PATH="/opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4/bin${PATH:+:$PATH}";
[ ! -d /opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4/lib ] || export DYLD_FALLBACK_LIBRARY_PATH="/opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4/lib${DYLD_FALLBACK_LIBRARY_PATH:+:$DYLD_FALLBACK_LIBRARY_PATH}";
[ ! -d /opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4/lib/python ] || export PYTHONPATH="/opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4/lib/python${PYTHONPATH:+:$PYTHONPATH}";
export ROOTSYS="/opt/alja/cmssw-462/osx106_amd64_gcc462/lcg/root/5.32.00-cms4";


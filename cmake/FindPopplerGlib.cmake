# - Try to find PopplerGlib 
# Once done, this will define
#
#  PopplerGlib_FOUND - system has PopplerGlib
#  PopplerGlib_INCLUDE_DIRS - the PopplerGlib include directories
#  PopplerGlib_LIBRARIES - link these to use PopplerGlib

include(LibFindMacros)


libfind_package(PopplerGlib GObject)
libfind_pkg_detect(PopplerGlib poppler-glib
  FIND_PATH poppler.h PATH_SUFFIXES poppler-glib
  FIND_LIBRARY poppler-glib
)
libfind_process(PopplerGlib)

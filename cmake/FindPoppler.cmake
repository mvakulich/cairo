# - Try to find Poppler 
# Once done, this will define
#
#  Poppler_FOUND - system has Poppler
#  Poppler_INCLUDE_DIRS - the Poppler include directories
#  Poppler_LIBRARIES - link these to use Poppler

include(LibFindMacros)

libfind_package(Poppler GObject)
libfind_pkg_detect(Poppler poppler-glib
  FIND_PATH poppler.h PATH_SUFFIXES poppler-glib
  FIND_LIBRARY poppler-glib
)
libfind_process(Poppler)

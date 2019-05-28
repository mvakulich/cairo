project(cairo)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package(Pixman REQUIRED)
find_package(PNG REQUIRED)
find_package(ZLIB REQUIRED)
find_package(FREETYPE)
find_package(Threads)
find_package(Fontconfig)
find_package(OPENGL)
find_package(Glib)
find_package(PopplerGlib)


message(STATUS "FREETYPE_LIBRARY ${FREETYPE_LIBRARY}")
if(APPLE)
    message(STATUS "MAC OS X")
    
endif()

include(Configure_config.cmake)
include(Configure_features.cmake)
include_directories(${CMAKE_BINARY_DIR})

if(CAIRO_HAS_PTHREAD)
	list(APPEND CAIRO_LIBS -lpthread)
endif()

if (WIN32)
    set(CAIRO_LIBS gdi32 msimg32 user32 winmm)
endif()

include_directories(${PIXMAN_INCLUDE_DIR} "/usr/local/include/freetype2" ${PNG_INCLUDE_DIR} ${ZLIB_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR})
list(APPEND CAIRO_LIBS  ${PIXMAN_LIBRARY} ${PNG_LIBRARY} ${ZLIB_LIBRARY} ${FREETYPE_LIBRARY})

if(FONTCONFIG_FOUND)
    list(APPEND CAIRO_LIBS ${FONTCONFIG_LIBRARY})
endif()


if(LibRSVG_FOUND)
    list(APPEND CAIRO_LIBS ${LibRSVG_LIBRARIES})
endif()

if(OPENGL_FOUND)
    list(APPEND CAIRO_LIBS ${OPENGL_LIBRARIES})
endif()



if(APPLE)
    find_library(ObjC objc)
	find_library(CoreFoundation CoreFoundation)
	find_library(IOKit IOKit)
    find_library(AppKit AppKit)
    if(OpenGL_FOUND)
        find_library(OpenGL OpenGL)
        include_directories(${OpenGL}/HEADERS)
    endif()
    
    list(APPEND CAIRO_LIBS ${CoreFoundation} ${IOKit} ${ObjC} ${AppKit} ${OpenGL})
endif()



include_directories(src)
add_subdirectory(src)

add_subdirectory(util/cairo-script)
add_subdirectory(util/cairo-pdf)

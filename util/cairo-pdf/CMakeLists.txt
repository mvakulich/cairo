set(EXTRA_PROGRAMS cairo-pdf)

set(CMAKE_CXX_FLAGS -I${PROJECT_SOURCE_DIR}/src -I${PROJECT_SOURCE_DIR}/src)

add_executable(cairo-pdf pdf2script)
include_directories(${Glib_INCLUDE_DIRS} ${PopplerGlib_INCLUDE_DIRS} )

target_link_libraries(cairo-pdf cairo ${CAIRO_LIBS} ${Glib_LIBRARIES} ${PopplerGlib_LIBRARIES} cairo-static)

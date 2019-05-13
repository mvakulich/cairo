
include (sources.cmake)

set(lib_LTLIBRARIES libcairo-script-interpreter.la)
set(EXTRA_PROGRAMS csi-replay csi-exec csi-bind)

set(CMAKE_CXX_FLAGS -I${PROJECT_SOURCE_DIR}/src -I${PROJECT_SOURCE_DIR}/src)

set(SHARED_SOURCES 
	${libcairo_script_interpreter_sources}
)


add_executable(csi-replay csi-replay.c ${SHARED_SOURCES})
target_link_libraries(csi-replay ${CAIRO_LIBS} cairo-static)

add_executable(csi-exec csi-exec.c ${SHARED_SOURCES})
target_link_libraries(csi-exec ${CAIRO_LIBS} cairo-static)




if(CAIRO_HAS_SCRIPT_SURFACE)
	add_executable(csi-trace csi-trace.c ${SHARED_SOURCES})
	target_link_libraries(csi-exec ${CAIRO_LIBS} cairo-static)
endif()

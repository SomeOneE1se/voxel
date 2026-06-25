######  16.06.2026  p@nsk
######  external libs cmake file
################################################################################

add_subdirectory(glad)

add_subdirectory(glfw)
set(GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL        OFF CACHE BOOL "" FORCE)

################################################################################
if (NOT UNIX)
    set(ZLIB_BUILD_EXAMPLES OFF CACHE BOOL "")
    add_subdirectory(zlib)
    set_target_properties(zlibstatic PROPERTIES POSITION_INDEPENDENT_CODE ON)

    set(PNG_TESTS   OFF CACHE BOOL "")
    set(PNG_SHARED  OFF CACHE BOOL "")
    set(PNG_STATIC  ON  CACHE BOOL "")
    set(PNG_TOOLS   OFF CACHE BOOL "")
    set(ZLIB_ROOT           ${CMAKE_CURRENT_BINARY_DIR}/extern/zlib)
    set(ZLIB_INCLUDE_DIR    ${CMAKE_CURRENT_SOURCE_DIR}/extern/zlib
                            ${CMAKE_CURRENT_BINARY_DIR}/extern/zlib)
    set(ZLIB_LIBRARY zlibstatic)

    add_subdirectory(lpng)
endif()

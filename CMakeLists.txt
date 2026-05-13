cmake_minimum_required( VERSION 3.31)

set( PROJECT_NAME voxel)
project( ${PROJECT_NAME} LANGUAGES CXX)

set( CMAKE_CXX_STANDARD		    14)
set( CMAKE_CXX_STANDARD_REQUIRED    ON)
set( CMAKE_CXX_FLAGS		    "-Wall")
set( CMAKE_EXPORT_COMPILE_COMMANDS  1)

add_subdirectory( extern)
include_directories( project)

add_executable(	${PROJECT_NAME}
#####	SOURCE	#####
    project/main.cpp

    project/window/window.cpp
    project/window/events.cpp

    project/graphics/shader.cpp

#####	LIB SRC	#####

#####	HEADER	#####
    project/project.h

    project/window/window.h
    project/window/events.h

    project/graphics/shader.h

#####	LIB HDR	#####
    project/uni/uni_types.h
    project/uni/uni_debug.h
)

target_include_directories( ${PROJECT_NAME} PRIVATE extern/glew/include)
target_link_libraries( ${PROJECT_NAME}	    PRIVATE glew)
target_link_libraries( ${PROJECT_NAME}	    PRIVATE glad)
target_link_libraries( ${PROJECT_NAME}	    PRIVATE glfw)


######  16.06.2026  p@nsk
######  root cmake file
###############################################################################
cmake_minimum_required(VERSION 3.31 FATAL_ERROR)

set(PROJECT_NAME    voxel)
project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD              17)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_FLAGS                 "-Wall")

###############################################################################

add_subdirectory(extern)
add_subdirectory(project)
add_subdirectory(res)

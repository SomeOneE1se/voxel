######  16.06.2026  p@nsk
######	project cmake file
###############################################################################
cmake_minimum_required(VERSION 3.31)
set(NAME			main)
set(NAME_UNI_LIB	uni_lib)

###############################################################################
set(	SOURCES_MAIN
	main/main.cpp
	main/project.h
	main/constants.h
)

set(	SOURCES_MANAGER
	manager/manager.cpp
	manager/manager.h
	manager/png_loading.cpp
)

set(	SOURCES_GRAPHICS
	graphics/shader.cpp
	graphics/shader.h
	graphics/texture.cpp
	graphics/texture.h
)

set(	SOURCES_WINDOW
	window/events.cpp
	window/events.h
	window/window.cpp
	window/window.h
)

set(	SOURCES_UNI_LIB
	uni/source/uni_func.cpp

	uni/include/uni_func.h
	uni/include/uni_base_types.h
	uni/include/uni_user_types.h
	uni/include/uni_debug.h
)

###############################################################################
add_library(${NAME_UNI_LIB}	STATIC	${SOURCES_UNI_LIB})

target_include_directories(${NAME_UNI_LIB}	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/uni/include
)

###############################################################################
add_executable(${NAME}
	${SOURCES_MAIN}
	${SOURCES_MANAGER}
	${SOURCES_GRAPHICS}
	${SOURCES_WINDOW}
)

target_include_directories(${NAME}	PUBLIC	${CMAKE_CURRENT_SOURCE_DIR}/main)
target_include_directories(${NAME}	PUBLIC	${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${NAME}	PRIVATE	uni_lib)

target_link_libraries(${NAME}	PRIVATE	glad		glfw)

if (NOT UNIX)
	target_link_libraries(${NAME}	PRIVATE	png_static	zlibstatic)
else()
	target_link_libraries(${NAME}	PRIVATE	png)
endif()

set_target_properties(	${NAME}	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_custom_command( TARGET ${NAME} POST_BUILD
					COMMAND ${CMAKE_COMMAND} -E copy_directory
					${CMAKE_SOURCE_DIR}/res/resources $<TARGET_FILE_DIR:${NAME}>)

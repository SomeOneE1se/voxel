######  16.06.2026  p@nsk
######  res cmake file
################################################################################
file(GLOB_RECURSE   RESOURCE_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/resources/shaders/*.glsl
    ${CMAKE_CURRENT_SOURCE_DIR}/resources/textures/*.png
)

add_custom_target(resources SOURCES
    ${RESOURCE_FILES}
)

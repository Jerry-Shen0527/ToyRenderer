aux_source_directory(. Renderer_src)
include_directories(${PROJECT_SOURCE_DIR}/include/)
add_library(Renderer ${Renderer_src})
target_link_libraries(Renderer glfw)
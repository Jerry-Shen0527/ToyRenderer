aux_source_directory(. Renderer_src)
include_directories(${PROJECT_SOURCE_DIR}/include/)
find_package(assimp REQUIRED)
include_directories(${ASSIMP_INCLUDE_DIRS})

add_library(Renderer ${Renderer_src})

target_link_libraries(Renderer glfw)
target_link_libraries(Renderer assimp::assimp)

message("${assimp_libraries}")
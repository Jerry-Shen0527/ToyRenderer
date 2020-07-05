# 设置 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.14)

project("ToyRenderer")

set(CMAKE_DEBUG_POSTFIX d)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(glew REQUIRED)

add_subdirectory("src")
add_subdirectory("include")




cmake_minimum_required(VERSION 2.4)

project(hello_world)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(app main.c cparser.c)  # be sure there's exactly one main() function in the source files

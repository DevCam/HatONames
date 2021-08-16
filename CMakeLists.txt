cmake_minimum_required(VERSION 3.20)

project(
  HatONames
  VERSION 0.1
  DESCRIPTION "Pull Names out of a Hat"
  LANGUAGES C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/bin)

add_compile_options(-Wall -Wextra -Wpedantic)

# The compiled library code is here
add_subdirectory(src)

# The executable code is here
add_subdirectory(app)
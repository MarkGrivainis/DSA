cmake_minimum_required(VERSION 4.2)
project(MyDSALibrary VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 1. Create the Library
# We include headers from the 'include' directory
add_library(dsa_lib
    src/linked_list.cpp
)

target_include_directories(dsa_lib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# 2. Include Tests
enable_testing()
add_subdirectory(tests)

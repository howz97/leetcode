cmake_minimum_required(VERSION 3.16)
project(leetcode_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB CPP_SOURCES "*.cpp")

foreach(source_file IN LISTS CPP_SOURCES)
    get_filename_component(target_name "${source_file}" NAME_WE)
    add_executable(${target_name} ${source_file})
endforeach()

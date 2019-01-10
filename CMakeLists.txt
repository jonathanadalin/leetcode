cmake_minimum_required (VERSION 2.6)

project (leetcode)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

file(GLOB_RECURSE leetcode_sources "src/*.cpp")
file(GLOB_RECURSE leetcode_headers "src/*.h")

set (leetcode_include_dir "")
foreach (_headerFile ${leetcode_headers})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND leedcode_include_dir ${_dir})
endforeach()
list(REMOVE_DUPLICATES leetcode_include_dir)

add_executable(bin/leetcode.out ${leetcode_sources})
target_include_directories(bin/leetcode.out PRIVATE ${leetcode_include_dir})

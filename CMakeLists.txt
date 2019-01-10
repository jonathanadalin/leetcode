cmake_minimum_required (VERSION 2.6)

project (leetcode)

file(GLOB_RECURSE leetcode_sources "src/*.cpp")
file(GLOB_RECURSE leetcode_headers "src/*.h")

set (leetcode_include_dir "")
foreach (_headerFile ${leetcode_headers})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND leedcode_include_dir ${_dir})
endforeach()
list(REMOVE_DUPLICATES leetcode_include_dir)

add_executable(leetcode ${leetcode_sources})
target_include_directories(leetcode PRIVATE ${leetcode_include_dir})

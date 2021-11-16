cmake_minimum_required(VERSION 3.20)
project(mp2_list)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(mp2_list
        include/list.h
        src/list.cpp
        test/test_list.cpp
        test/test_main.cpp)

add_subdirectory(Google_tests/lib/googletest-master)
include_directories(Google_tests/lib/googletest-master/googletest/include)
target_link_libraries(mp2_list gtest)
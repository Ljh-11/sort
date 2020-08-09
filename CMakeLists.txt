cmake_minimum_required(VERSION 3.16)
project(sort)

set(CMAKE_CXX_STANDARD 14)

add_executable(InsertSort InsertSort.cpp)
add_executable(ChangeSort ChangeSort.cpp)
add_executable(SelectSort SelectSort.cpp)
add_executable(MergeSort MergeSort.cpp)

add_executable(test test.c)
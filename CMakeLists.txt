cmake_minimum_required(VERSION 3.5)

project(sol_runtime)

add_library(sol_runtime SHARED 
    my_ispc.cpp my_x86.cpp
)

target_link_libraries(sol_runtime mxnet)

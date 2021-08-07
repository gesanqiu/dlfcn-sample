# create by Ricardo Lu in 08-07-2021

cmake_minimum_required(VERSION 3.10)

project(dlfcn-libs)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

add_library(sample_lib_1
    SHARED
    libmath_1.cpp
    Interface_1.cpp
)

add_library(sample_lib_2
    SHARED
    libmath_2.cpp
    Interface_2.cpp
)
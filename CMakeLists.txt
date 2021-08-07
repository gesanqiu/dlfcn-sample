# create by Ricardo Lu in 08-07-2021

cmake_minimum_required(VERSION 3.10)

project(dlfcn-sample)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(libs)

add_executable(${PROJECT_NAME}
    main.cpp
)

target_link_libraries(${PROJECT_NAME}
    dl
)
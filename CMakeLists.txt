cmake_minimum_required(VERSION 3.20)
project(Program2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Program2 main.c
        libs/algoritms/algoritm.c libs/algoritms/algoritm.h
        libs/algoritms/array/array.c libs/algoritms/array/array.h
        libs/data_structure/vector/vector.c libs/data_structure/vector/vector.h)

add_subdirectory(libs)

target_link_libraries(Program2 algoritms)
target_link_libraries(Program2 data_structure)
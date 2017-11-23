cmake_minimum_required(VERSION 3.8)
project(cclass)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c main.h  create.c Joseph.c)
add_executable(cclass ${SOURCE_FILES})
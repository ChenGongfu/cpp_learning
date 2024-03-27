cmake_minimum_required(VERSION 3.28)
project(atest LANGUAGES C)
add_compile_definitions(DEBUG)
add_executable(atest atest.c)
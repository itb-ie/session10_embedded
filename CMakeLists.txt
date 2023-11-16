cmake_minimum_required(VERSION 3.26)
project(session10_embedded C)

set(CMAKE_C_STANDARD 11)

add_executable(session10_embedded main.c
        tree.h
        tree.c)

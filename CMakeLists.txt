cmake_minimum_required(VERSION 3.9)
project(dsaa C)

set(CMAKE_C_STANDARD 99)

add_executable(dsaa main.c SqlList/C/SeqList.c SqlList/C/SeqList.h)
cmake_minimum_required(VERSION 3.9)
project(dsaa C)

set(CMAKE_C_STANDARD 99)

add_executable(dsaa main.c SeqList/C/main.c SeqList/C/main.h LinkList/C/main.c LinkList/C/main.h Stack/C/LinkStack/main.c Stack/C/LinkStack/main.h)
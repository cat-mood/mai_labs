cmake_minimum_required(VERSION 3.22)

project(kp7)

set(SOURCES sources/main.c sources/tree.c)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic -std=c99 -Wall")

add_executable(${PROJECT_NAME} ${SOURCES})
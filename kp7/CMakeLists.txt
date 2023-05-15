cmake_minimum_required(VERSION 3.22)

project(kp7)

set(SOURCES sources/main.c sources/dbl_vec.c)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pedantic -std=c99 -Wall")

# include_directories("headers/")

add_executable(${PROJECT_NAME} ${SOURCES})

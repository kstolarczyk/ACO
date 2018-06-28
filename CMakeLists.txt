cmake_minimum_required(VERSION 3.10)
project(ACO)

set(CMAKE_CXX_STANDARD 14)

add_executable(ACO main.cpp Ant.cpp Ant.h headers.h)
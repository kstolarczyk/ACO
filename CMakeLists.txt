cmake_minimum_required(VERSION 3.10)
project(ACO)

set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS -pthread)
add_executable(ACO main.cpp Ant.cpp Ant.h headers.h config.h Graph.cpp Graph.h Edge.cpp Edge.h SpecialAnt.cpp SpecialAnt.h instances.cpp instances.h)
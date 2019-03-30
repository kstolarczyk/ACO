cmake_minimum_required(VERSION 3.10)
project(ACO)


SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++11 -pthread")
find_package(Threads)
add_executable(ACO main.cpp Ant.cpp Ant.h headers.h config.h Graph.cpp Graph.h Edge.cpp Edge.h SpecialAnt.cpp SpecialAnt.h instances.cpp instances.h)
target_link_libraries(ACO ${CMAKE_THREAD_LIBS_INIT})
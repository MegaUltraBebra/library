cmake_minimum_required(VERSION 3.20)
project(bufer)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES library.cpp library.h)

add_executable(bufer main.cpp library.cpp bigInt.cpp)

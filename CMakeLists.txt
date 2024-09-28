cmake_minimum_required(VERSION 3.29)
project(DataFlowAPI)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataFlowAPI main.cpp
        DataFlow/Iris.API/Iris.Color/Iris.Color.h
        DataFlow/Iris.API/Iris.Color/Iris.Color.cpp)

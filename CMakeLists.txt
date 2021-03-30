cmake_minimum_required(VERSION 2.8)
project(Z2)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")
add_executable(hahaha main.cpp CComplexVector.cpp CComplexVector0.cpp CComplexVector1.cpp CComplexPoint.cpp CComplexPoint.h CComplexVector.h CComplexVector0.h CComplexVector1.h CComplexVectorFabric.h CComplexVectorFabric0.h CComplexVectorFabric1.h )
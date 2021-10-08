cmake_minimum_required(VERSION 3.20)
project(Neuron_Network)

set(CMAKE_CXX_STANDARD 20)
include_directories("${PROJECT_SOURCE_DIR}/inc/")
add_executable(Neuron_Network main.cpp Network.hpp Functions.hpp Expression.hpp Tensor.hpp Layer.hpp Apply.hpp Operations.hpp NodeTree.h Node.hpp GraphCalc.h)


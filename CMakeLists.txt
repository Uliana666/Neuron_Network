cmake_minimum_required(VERSION 3.20)
project(Neuron_Network)

set(CMAKE_CXX_STANDARD 17)

add_executable(Neuron_Network main.cpp Network.cpp Network.h Functions.cpp Functions.h AbstractActivationFunction.h const.h)


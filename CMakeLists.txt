cmake_minimum_required(VERSION 3.24)
project(M3OEP_taschulz)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(M3OEP_taschulz
        Asset.cpp
        Asset.h
        IrFrame.cpp
        IrFrame.h
        main.cpp)

cmake_minimum_required(VERSION 3.19)
project(Task_27_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        Task_27_2 main.cpp
        src/Figure.cpp
        src/Circle.cpp
        src/Square.cpp
        src/Triangle.cpp
        src/Rectangle.cpp
        src/Equalsided.cpp)
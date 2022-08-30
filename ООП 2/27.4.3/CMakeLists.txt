cmake_minimum_required(VERSION 3.19)
project(Task_27_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        Task_27_3 main.cpp
        src/TeamMember.cpp
        src/TeamManager.cpp
        src/TopManager.cpp
        src/Employee.cpp )
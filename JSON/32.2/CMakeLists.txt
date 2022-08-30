cmake_minimum_required(VERSION 3.19)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(untitled1 main.cpp)

target_link_libraries(untitled1 PRIVATE nlohmann_json::nlohmann_json)
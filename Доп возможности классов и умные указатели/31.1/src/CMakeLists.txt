cmake_minimum_required(VERSION 3.0.0)

set(SOURCES src/main.cpp src/shared_ptr_toy.cpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(Smartptr ${SOURCES})

target_include_directories(Smartptr PUBLIC ${MY_INCLUDE_DIR})
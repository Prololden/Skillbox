cmake_minimum_required(VERSION 3.0.0)

set(SOURCES main.cpp station.cpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(Railway ${SOURCES})

target_include_directories(Railway PUBLIC ${MY_INCLUDE_DIR})

#Подключаем потоки
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads)
target_link_libraries(Railway Threads::Threads)
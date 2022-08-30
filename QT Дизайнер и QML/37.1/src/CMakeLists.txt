cmake_minimum_required(VERSION 3.0.0)


set(SOURCES main.cpp calculator.cpp)
set(HEADERS ${MY_INCLUDE_DIR}/calculator.h)
#set(SOURCESUI calc.ui)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_PREFIX_PATH "/home/oktan/Qt/5.15.2/gcc_64/lib/cmake")



find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
qt5_wrap_cpp (MOC_SOURCES ${HEADERS})
#qt5_wrap_ui (MOC_SOURCESUI ${SOURCESUI})

add_executable(Calc ${SOURCES} ${MOC_SOURCESUI} ${MOC_SOURCES})

target_link_libraries(Calc Qt5::Core Qt5::Gui Qt5::Widgets)
target_include_directories(Calc PUBLIC ${MY_INCLUDE_DIR})
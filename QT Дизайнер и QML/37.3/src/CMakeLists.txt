cmake_minimum_required(VERSION 3.0.0)


set(SOURCES main.cpp wincontrol.cpp )
set(HEADERS ${MY_INCLUDE_DIR}/wincontrol.h)
set(SOURCESUI control.ui)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_PREFIX_PATH "/home/oktan/Qt/5.15.2/gcc_64/lib/cmake")



find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
qt5_wrap_cpp (MOC_SOURCES ${HEADERS})
qt5_wrap_ui (MOC_SOURCESUI ${SOURCESUI})

add_executable(Control ${SOURCES} ${MOC_SOURCES} ${MOC_SOURCESUI} )

target_link_libraries(Control Qt5::Core Qt5::Gui Qt5::Widgets)
target_include_directories(Control PUBLIC ${MY_INCLUDE_DIR})
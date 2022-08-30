cmake_minimum_required(VERSION 3.18.4)

set(MAIN_SOURCES main.cpp wmain.cpp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)


#----------------Qt-------------------------
if(WIN32)
  message("Version Qt for Windows")
  set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/mingw81_64/lib/cmake")
elseif(UNIX)
  message("Version Qt for Linux")
  set(CMAKE_PREFIX_PATH "/home/oktan/Qt/5.15.2/gcc_64/lib/cmake")
endif()

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

message("Looking for Qt...")

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

if(${Qt5_FOUND})
    message("Found Qt [${Qt5_VERSION}]")
else()
    message("Not Found Qt :(")
endif()

#qt5_generate_moc(main.cpp main.moc TARGET QtWeb)
qt5_wrap_cpp (MAIN_SOURCES ${MY_INCLUDE_DIR}/wmain.h)
#qt5_wrap_cpp (MAIN_SOURCES ${MY_INCLUDE_DIR}/scaledpixmap.h)
#------------------------------------------


add_executable(Blurimage ${MAIN_SOURCES})

target_link_libraries(Blurimage Qt5::Core Qt5::Widgets)
target_include_directories(Blurimage PUBLIC ${MY_INCLUDE_DIR})
cmake_minimum_required(VERSION 3.0.0)

set(SOURCES main.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(CMAKE_USE_OPENSSL OFF)
set(CPR_ENABLE_SSL OFF)
set(CPR_BUILD_TESTS_SSL OFF)


include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG f4622efcb59d84071ae11404ae61bd821c1c344b) # the commit hash for 1.6.2
FetchContent_MakeAvailable(cpr)



add_executable(Httpbin ${SOURCES})


target_include_directories(Httpbin PUBLIC ${MY_INCLUDE_DIR})
target_link_libraries(Httpbin PRIVATE cpr::cpr)
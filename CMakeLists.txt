cmake_minimum_required(VERSION 3.10)

project(libgtfs LANGUAGES CXX VERSION "0.1")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_library(gtfs SHARED src/gtfs.cpp src/utils/types.cpp)
target_include_directories(gtfs PRIVATE include)

add_subdirectory(external/Catch2)

add_executable(gtfs-tests tests/test.cpp)
target_link_libraries(gtfs-tests PRIVATE Catch2::Catch2WithMain)
cmake_minimum_required(VERSION 3.26)
project(bits)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(benchmark REQUIRED)

set(SOURCE bits.cc)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_executable(bits ${SOURCE})
target_link_libraries(bits benchmark::benchmark)

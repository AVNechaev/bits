cmake_minimum_required(VERSION 3.26)
project(CoolProject)

find_package(benchmark REQUIRED)

set(SOURCE bits.cc)

add_executable(cool ${SOURCE})
target_link_libraries(cool benchmark::benchmark)

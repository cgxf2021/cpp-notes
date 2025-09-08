cmake_minimum_required(VERSION 3.10)

project(flow_builder)

set(CMAKE_CXX_STANDARD 17)

add_executable(flow_builder main.cpp html_builder.cpp)

target_include_directories(flow_builder PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

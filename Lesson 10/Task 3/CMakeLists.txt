cmake_minimum_required(VERSION 3.22.0)

project(Task_3)

add_library(leaver_library SHARED leaver.h leaver.cpp)

target_include_directories(leaver_library PUBLIC "./")

add_executable(leaver_program main.cpp)

target_link_libraries(leaver_program leaver_library)
cmake_minimum_required(VERSION 3.22.0)

project(Task_5)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_subdirectory("FiguresLib")

add_executable(figures_program main.cpp)

target_link_libraries(figures_program figures_library)
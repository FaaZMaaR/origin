cmake_minimum_required(VERSION 3.10)

project(task_1)

set(CMAKE_PREFIX_PATH C:/Catch2)

find_package(Catch2 3 REQUIRED)

add_executable(${PROJECT_NAME} main.cpp my_list.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ./)

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)
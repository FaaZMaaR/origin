cmake_minimum_required(VERSION 3.22.0)
project(tcp_test)

add_executable(tcp_server tcp_server.cpp)
add_executable(tcp_client tcp_client.cpp)
target_link_libraries(tcp_server PRIVATE Ws2_32.lib)
target_link_libraries(tcp_client PRIVATE Ws2_32.lib)
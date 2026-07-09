cmake_minimum_required(VERSION 3.20)

project(
    AlgoKitGraph
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(
    algokit_graph
    cpp/src/graph.cpp
)

add_executable(
    graph_demo
    app/main.cpp
)

target_link_libraries(
    graph_demo
    PRIVATE
    algokit_graph
)

target_include_directories(
    algokit_graph
    PUBLIC
    cpp/include
)
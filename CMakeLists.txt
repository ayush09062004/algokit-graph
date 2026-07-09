cmake_minimum_required(VERSION 3.20)

project(
    AlgoKitGraph
    VERSION 0.1.0
    LANGUAGES CXX
)

#--------------------------------------------------
# C++ Standard
#--------------------------------------------------

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#--------------------------------------------------
# Enable Testing
#--------------------------------------------------

enable_testing()

#--------------------------------------------------
# AlgoKit Library
#--------------------------------------------------

add_library(
    algokit_graph

    #==========================
    # Core
    #==========================

    cpp/src/graph.cpp

    #==========================
    # BFS
    #==========================

    cpp/src/bfs.cpp
    cpp/src/bfs_result.cpp

    #==========================
    # DFS
    #==========================

    cpp/src/dfs.cpp
    cpp/src/dfs_result.cpp

    #==========================
    # Connected Components
    #==========================

    cpp/src/connected_components.cpp
    cpp/src/connected_components_result.cpp

    #==========================
    # Internal Engines
    #==========================

    cpp/src/dfs_engine.cpp
)

target_include_directories(
    algokit_graph
    PUBLIC
        cpp/include
)

#--------------------------------------------------
# Demo Application
#--------------------------------------------------

add_executable(
    graph_demo
    app/main.cpp
)

target_link_libraries(
    graph_demo
    PRIVATE
        algokit_graph
)

#--------------------------------------------------
# BFS Tests
#--------------------------------------------------

add_executable(
    test_bfs
    tests/test_bfs.cpp
)

target_link_libraries(
    test_bfs
    PRIVATE
        algokit_graph
)

add_test(
    NAME BFS
    COMMAND test_bfs
)

#--------------------------------------------------
# DFS Tests
#--------------------------------------------------

add_executable(
    test_dfs
    tests/test_dfs.cpp
)

target_link_libraries(
    test_dfs
    PRIVATE
        algokit_graph
)

add_test(
    NAME DFS
    COMMAND test_dfs
)

#--------------------------------------------------
#Connected Components Tests
#--------------------------------------------------


add_executable(
    test_connected_components
    tests/test_connected_components.cpp
)

target_link_libraries(
     test_connected_components
     PRIVATE
         algokit_graph
 )

add_test(
     NAME ConnectedComponents
     COMMAND test_connected_components
 )
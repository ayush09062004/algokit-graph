cmake_minimum_required(VERSION 3.20)

project(
    AlgoKitGraph
    VERSION 0.1.0
    LANGUAGES CXX
)

find_package(pybind11 CONFIG REQUIRED)

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
    # Cycle Detection
    #==========================

    cpp/src/cycle_detection.cpp

    #==========================
    # Directed Cycle Detection
    #==========================

    cpp/src/directed_cycle_detection.cpp

    #==========================
    # Topological Sort
    #==========================

    cpp/src/topological_sort.cpp
    cpp/src/topological_sort_result.cpp

    #==========================
    # Kahn Topological Sort
    #==========================

    cpp/src/kahn_topological_sort.cpp
    cpp/src/kahn_topological_sort_result.cpp

    #==========================
    # Shortest Path
    #==========================

    cpp/src/shortest_path.cpp
    cpp/src/shortest_path_result.cpp

    #==========================
    # Internal Engines
    #==========================

    cpp/src/dfs_engine.cpp
)

set_target_properties(
    algokit_graph
    PROPERTIES
    POSITION_INDEPENDENT_CODE ON
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
# Connected Components Tests
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

#--------------------------------------------------
# Cycle Detection Tests
#--------------------------------------------------

add_executable(
    test_cycle_detection
    tests/test_cycle_detection.cpp
)

target_link_libraries(
    test_cycle_detection
    PRIVATE
        algokit_graph
)

add_test(
    NAME CycleDetection
    COMMAND test_cycle_detection
)


#--------------------------------------------------
# Directed Cycle Detection Tests
#--------------------------------------------------

add_executable(
    test_directed_cycle_detection
    tests/test_directed_cycle_detection.cpp
)

target_link_libraries(
    test_directed_cycle_detection
    PRIVATE
    algokit_graph
)

add_test(
    NAME DirectedCycleDetection
    COMMAND test_directed_cycle_detection
)


#--------------------------------------------------
# Topological Sort Tests
#--------------------------------------------------

add_executable(
    test_topological_sort
    tests/test_topological_sort.cpp
)

target_link_libraries(
    test_topological_sort
    PRIVATE
    algokit_graph
)

add_test(
    NAME TopologicalSort
    COMMAND test_topological_sort
)


#--------------------------------------------------
# Kahn Topological Sort Tests
#--------------------------------------------------

add_executable(
    test_kahn_topological_sort
    tests/test_kahn_topological_sort.cpp
)

target_link_libraries(
    test_kahn_topological_sort
    PRIVATE
    algokit_graph
)

add_test(
    NAME KahnTopologicalSort
    COMMAND test_kahn_topological_sort
)

#--------------------------------------------------
# Shortest Path Tests
#--------------------------------------------------

add_executable(
    test_shortest_path
    tests/test_shortest_path.cpp
)

target_link_libraries(
    test_shortest_path
    PRIVATE
    algokit_graph
)

add_test(
    NAME ShortestPath
    COMMAND test_shortest_path
)


#--------------------------------------------------
# Python Module
#--------------------------------------------------

pybind11_add_module(
    algokit
    bindings/module.cpp
)

target_link_libraries(
    algokit
    PRIVATE
    algokit_graph
)

target_include_directories(
    algokit
    PRIVATE
    cpp/include
)

#cmake -B build
#cmake --build build
#ctest --test-dir build --output-on-failure 
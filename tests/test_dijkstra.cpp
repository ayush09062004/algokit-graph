#include <iostream>
#include <stdexcept>
#include <vector>

#include "algokit/graph.hpp"
#include "test_utils.hpp"

using namespace algokit;

//--------------------------------------------------
// Simple Weighted Graph
//--------------------------------------------------

void test_simple_graph()
{
    RUN_TEST("Simple Weighted Graph");

    Graph graph = Graph::directed(5);

    graph.add_edge(0, 1, 4.0);
    graph.add_edge(0, 2, 1.0);
    graph.add_edge(2, 1, 2.0);
    graph.add_edge(1, 3, 1.0);
    graph.add_edge(2, 3, 5.0);
    graph.add_edge(3, 4, 3.0);

    auto result = graph.dijkstra(0);

    EXPECT_EQ(result.distance(0), 0.0);
    EXPECT_EQ(result.distance(1), 3.0);
    EXPECT_EQ(result.distance(2), 1.0);
    EXPECT_EQ(result.distance(3), 4.0);
    EXPECT_EQ(result.distance(4), 7.0);

    std::vector<std::size_t> expected =
    {
        0,
        2,
        1,
        3,
        4
    };

    EXPECT_TRUE(
        result.path_to(4) == expected
    );

    PASS_TEST("Simple Weighted Graph");
}

//--------------------------------------------------
// Multiple Paths
//--------------------------------------------------

void test_multiple_paths()
{
    RUN_TEST("Multiple Paths");

    Graph graph = Graph::directed(4);

    graph.add_edge(0,1,10.0);
    graph.add_edge(0,2,1.0);
    graph.add_edge(2,1,1.0);
    graph.add_edge(1,3,1.0);
    graph.add_edge(2,3,100.0);

    auto result = graph.dijkstra(0);

    EXPECT_EQ(result.distance(3), 3.0);

    std::vector<std::size_t> expected =
    {
        0,
        2,
        1,
        3
    };

    EXPECT_TRUE(
        result.path_to(3) == expected
    );

    PASS_TEST("Multiple Paths");
}

//--------------------------------------------------
// Disconnected Graph
//--------------------------------------------------

void test_disconnected_graph()
{
    RUN_TEST("Disconnected Graph");

    Graph graph = Graph::directed(5);

    graph.add_edge(0,1,2.0);
    graph.add_edge(1,2,2.0);

    auto result = graph.dijkstra(0);

    EXPECT_TRUE(result.is_reachable(0));
    EXPECT_TRUE(result.is_reachable(1));
    EXPECT_TRUE(result.is_reachable(2));

    EXPECT_TRUE(!result.is_reachable(3));
    EXPECT_TRUE(!result.is_reachable(4));

    EXPECT_TRUE(
        result.path_to(4).empty()
    );

    PASS_TEST("Disconnected Graph");
}

//--------------------------------------------------
// Zero Weight Edges
//--------------------------------------------------

void test_zero_weight_edges()
{
    RUN_TEST("Zero Weight Edges");

    Graph graph = Graph::directed(4);

    graph.add_edge(0,1,0.0);
    graph.add_edge(1,2,0.0);
    graph.add_edge(2,3,0.0);

    auto result = graph.dijkstra(0);

    EXPECT_EQ(result.distance(3), 0.0);

    std::vector<std::size_t> expected =
    {
        0,
        1,
        2,
        3
    };

    EXPECT_TRUE(
        result.path_to(3) == expected
    );

    PASS_TEST("Zero Weight Edges");
}

//--------------------------------------------------
// Single Vertex
//--------------------------------------------------

void test_single_vertex()
{
    RUN_TEST("Single Vertex");

    Graph graph = Graph::directed(1);

    auto result = graph.dijkstra(0);

    EXPECT_EQ(result.distance(0), 0.0);

    EXPECT_TRUE(
        result.path_to(0) ==
        std::vector<std::size_t>{0}
    );

    PASS_TEST("Single Vertex");
}

//--------------------------------------------------
// Invalid Source
//--------------------------------------------------

void test_invalid_source()
{
    RUN_TEST("Invalid Source");

    Graph graph = Graph::directed(3);

    EXPECT_THROW(
        graph.dijkstra(10),
        std::out_of_range
    );

    PASS_TEST("Invalid Source");
}

//--------------------------------------------------

int main()
{
    std::cout
        << "=====================================\n"
        << "AlgoKit Dijkstra Tests\n"
        << "=====================================\n\n";

    test_simple_graph();
    test_multiple_paths();
    test_disconnected_graph();
    test_zero_weight_edges();
    test_single_vertex();
    test_invalid_source();

    std::cout
        << "\n=====================================\n"
        << "All tests passed!\n"
        << "=====================================\n";

    return 0;
}
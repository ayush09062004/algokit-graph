#include <iostream>
#include <stdexcept>
#include <vector>

#include "algokit/graph.hpp"
#include "test_utils.hpp"

using namespace algokit;

//--------------------------------------------------
// Simple Graph
//--------------------------------------------------
//--------------------------------------------------
// Parallel Edges
//--------------------------------------------------

void test_parallel_edges()
{
    RUN_TEST("Parallel Edges");

    Graph graph = Graph::directed(2);

    graph.add_edge(0,1,3);
    graph.add_edge(0,1,10);   // expensive edge added last

    auto result = graph.floyd_warshall();

    EXPECT_EQ(result.distance(0,1),3.0);

    PASS_TEST("Parallel Edges");
}
void test_simple_graph()
{
    RUN_TEST("Simple Graph");

    Graph graph = Graph::directed(5);

    graph.add_edge(0, 1, 4);
    graph.add_edge(0, 2, 1);
    graph.add_edge(2, 1, 2);
    graph.add_edge(1, 3, 1);
    graph.add_edge(2, 3, 5);
    graph.add_edge(3, 4, 3);

    auto result = graph.floyd_warshall();

    EXPECT_EQ(result.distance(0,0), 0.0);
    EXPECT_EQ(result.distance(0,1), 3.0);
    EXPECT_EQ(result.distance(0,2), 1.0);
    EXPECT_EQ(result.distance(0,3), 4.0);
    EXPECT_EQ(result.distance(0,4), 7.0);

    std::vector<std::size_t> expected =
    {
        0,2,1,3,4
    };

    EXPECT_TRUE(
        result.path(0,4) == expected
    );

    PASS_TEST("Simple Graph");
}

//--------------------------------------------------
// Negative Edge
//--------------------------------------------------

void test_negative_edges()
{
    RUN_TEST("Negative Edges");

    Graph graph = Graph::directed(5);

    graph.add_edge(0,1,6);
    graph.add_edge(0,2,7);
    graph.add_edge(1,2,8);
    graph.add_edge(1,3,5);
    graph.add_edge(1,4,-4);
    graph.add_edge(2,3,-3);
    graph.add_edge(2,4,9);
    graph.add_edge(3,1,-2);
    graph.add_edge(4,3,7);

    auto result = graph.floyd_warshall();

    EXPECT_EQ(result.distance(0,4), -2.0);
    EXPECT_EQ(result.distance(0,3), 4.0);
    EXPECT_EQ(result.distance(0,1), 2.0);

    PASS_TEST("Negative Edges");
}

//--------------------------------------------------
// Disconnected Graph
//--------------------------------------------------

void test_disconnected_graph()
{
    RUN_TEST("Disconnected Graph");

    Graph graph = Graph::directed(5);

    graph.add_edge(0,1,2);
    graph.add_edge(1,2,3);

    auto result = graph.floyd_warshall();

    EXPECT_TRUE(result.is_reachable(0,2));

    EXPECT_TRUE(
        !result.is_reachable(0,4)
    );

    EXPECT_TRUE(
        result.path(0,4).empty()
    );

    PASS_TEST("Disconnected Graph");
}

//--------------------------------------------------
// Undirected Graph
//--------------------------------------------------

void test_undirected_graph()
{
    RUN_TEST("Undirected Graph");

    Graph graph = Graph::undirected(4);

    graph.add_edge(0,1,2);
    graph.add_edge(1,2,3);
    graph.add_edge(2,3,4);

    auto result = graph.floyd_warshall();

    EXPECT_EQ(result.distance(3,0), 9.0);

    std::vector<std::size_t> expected =
    {
        3,2,1,0
    };

    EXPECT_TRUE(
        result.path(3,0) == expected
    );

    PASS_TEST("Undirected Graph");
}

//--------------------------------------------------
// Single Vertex
//--------------------------------------------------

void test_single_vertex()
{
    RUN_TEST("Single Vertex");

    Graph graph = Graph::directed(1);

    auto result = graph.floyd_warshall();

    EXPECT_EQ(result.distance(0,0),0.0);

    EXPECT_TRUE(
        result.path(0,0)
        ==
        std::vector<std::size_t>{0}
    );

    PASS_TEST("Single Vertex");
}

//--------------------------------------------------
// Negative Cycle
//--------------------------------------------------

void test_negative_cycle()
{
    RUN_TEST("Negative Cycle");

    Graph graph = Graph::directed(3);

    graph.add_edge(0,1,1);
    graph.add_edge(1,2,-2);
    graph.add_edge(2,0,-2);

    EXPECT_THROW(
        graph.floyd_warshall(),
        std::logic_error
    );

    PASS_TEST("Negative Cycle");
}

//--------------------------------------------------

int main()
{
    std::cout
        << "=====================================\n"
        << "AlgoKit Floyd-Warshall Tests\n"
        << "=====================================\n\n";
    test_parallel_edges();
    test_simple_graph();
    test_negative_edges();
    test_disconnected_graph();
    test_undirected_graph();
    test_single_vertex();
    test_negative_cycle();

    std::cout
        << "\n=====================================\n"
        << "All tests passed!\n"
        << "=====================================\n";

    return 0;
}
#include <iostream>
#include <stdexcept>
#include <vector>

#include "algokit/graph.hpp"
#include "test_utils.hpp"

using namespace algokit;

//--------------------------------------------------
// Simple Graph
//--------------------------------------------------

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

    auto result = graph.bellman_ford(0);

    EXPECT_EQ(result.distance(0), 0.0);
    EXPECT_EQ(result.distance(1), 3.0);
    EXPECT_EQ(result.distance(2), 1.0);
    EXPECT_EQ(result.distance(3), 4.0);
    EXPECT_EQ(result.distance(4), 7.0);

    std::vector<std::size_t> expected =
    {
        0, 2, 1, 3, 4
    };

    EXPECT_TRUE(
        result.path_to(4) == expected
    );

    PASS_TEST("Simple Graph");
}

//--------------------------------------------------
// Negative Edges
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

    auto result = graph.bellman_ford(0);

    EXPECT_EQ(result.distance(0), 0.0);
    EXPECT_EQ(result.distance(1), 2.0);
    EXPECT_EQ(result.distance(2), 7.0);
    EXPECT_EQ(result.distance(3), 4.0);
    EXPECT_EQ(result.distance(4), -2.0);

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

    auto result = graph.bellman_ford(0);

    EXPECT_TRUE(result.is_reachable(0));
    EXPECT_TRUE(result.is_reachable(1));
    EXPECT_TRUE(result.is_reachable(2));

    EXPECT_TRUE(!result.is_reachable(3));
    EXPECT_TRUE(!result.is_reachable(4));

    EXPECT_TRUE(result.path_to(4).empty());

    PASS_TEST("Disconnected Graph");
}

//--------------------------------------------------
// Invalid Source
//--------------------------------------------------

void test_invalid_source()
{
    RUN_TEST("Invalid Source");

    Graph graph = Graph::directed(3);

    EXPECT_THROW(
        graph.bellman_ford(10),
        std::out_of_range
    );

    PASS_TEST("Invalid Source");
}

//--------------------------------------------------
// Reachable Negative Cycle
//--------------------------------------------------

void test_negative_cycle()
{
    RUN_TEST("Reachable Negative Cycle");

    Graph graph = Graph::directed(4);

    graph.add_edge(0,1,1);
    graph.add_edge(1,2,-1);
    graph.add_edge(2,1,-1);
    graph.add_edge(2,3,2);

    EXPECT_THROW(
        graph.bellman_ford(0),
        std::logic_error
    );

    PASS_TEST("Reachable Negative Cycle");
}

//--------------------------------------------------
// Unreachable Negative Cycle
//--------------------------------------------------

void test_unreachable_negative_cycle()
{
    RUN_TEST("Unreachable Negative Cycle");

    Graph graph = Graph::directed(6);

    graph.add_edge(0,1,2);
    graph.add_edge(1,2,2);

    graph.add_edge(3,4,-5);
    graph.add_edge(4,5,-5);
    graph.add_edge(5,3,-5);

    auto result = graph.bellman_ford(0);

    EXPECT_EQ(result.distance(2), 4.0);

    EXPECT_TRUE(!result.is_reachable(3));
    EXPECT_TRUE(!result.is_reachable(4));
    EXPECT_TRUE(!result.is_reachable(5));

    PASS_TEST("Unreachable Negative Cycle");
}

//--------------------------------------------------

int main()
{
    std::cout
        << "=====================================\n"
        << "AlgoKit Bellman-Ford Tests\n"
        << "=====================================\n\n";

    test_simple_graph();
    test_negative_edges();
    test_disconnected_graph();
    test_invalid_source();
    test_negative_cycle();
    test_unreachable_negative_cycle();

    std::cout
        << "\n=====================================\n"
        << "All tests passed!\n"
        << "=====================================\n";

    return 0;
}
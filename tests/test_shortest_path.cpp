#include <iostream>
#include <vector>

#include "algokit/graph.hpp"
#include "test_utils.hpp"

using namespace algokit;

//--------------------------------------------------

void test_simple_graph()
{
    RUN_TEST("Simple Graph");

    Graph graph = Graph::undirected(6);

    graph.add_edge(0,1);
    graph.add_edge(1,2);
    graph.add_edge(1,3);
    graph.add_edge(3,4);
    graph.add_edge(4,5);

    auto result = graph.shortest_path(0);

    EXPECT_EQ(result.distance(0), 0.0);
    EXPECT_EQ(result.distance(1), 1.0);
    EXPECT_EQ(result.distance(2), 2.0);
    EXPECT_EQ(result.distance(3), 2.0);
    EXPECT_EQ(result.distance(4), 3.0);
    EXPECT_EQ(result.distance(5), 4.0);

    std::vector<std::size_t> expected =
    {
        0,
        1,
        3,
        4,
        5
    };

    EXPECT_TRUE(
        result.path_to(5) == expected
    );

    PASS_TEST("Simple Graph");
}

//--------------------------------------------------

void test_disconnected_graph()
{
    RUN_TEST("Disconnected Graph");

    Graph graph = Graph::undirected(4);

    graph.add_edge(0,1);

    auto result = graph.shortest_path(0);

    EXPECT_TRUE(
        result.is_reachable(0)
    );

    EXPECT_TRUE(
        result.is_reachable(1)
    );

    EXPECT_TRUE(
        !result.is_reachable(2)
    );

    EXPECT_TRUE(
        !result.is_reachable(3)
    );

    PASS_TEST("Disconnected Graph");
}

//--------------------------------------------------

void test_single_vertex()
{
    RUN_TEST("Single Vertex");

    Graph graph = Graph::undirected(1);

    auto result =
        graph.shortest_path(0);

    EXPECT_EQ(
        result.distance(0),
        0.0
    );

    PASS_TEST("Single Vertex");
}

//--------------------------------------------------

void test_invalid_source()
{
    RUN_TEST("Invalid Source");

    Graph graph =
        Graph::undirected(3);

    EXPECT_THROW(
        graph.shortest_path(10),
        std::out_of_range
    );

    PASS_TEST("Invalid Source");
}

//--------------------------------------------------

int main()
{
    std::cout
        << "=====================================\n"
        << "AlgoKit Shortest Path Tests\n"
        << "=====================================\n\n";

    test_simple_graph();
    test_disconnected_graph();
    test_single_vertex();
    test_invalid_source();

    std::cout
        << "\n=====================================\n"
        << "All tests passed!\n"
        << "=====================================\n";

    return 0;
}
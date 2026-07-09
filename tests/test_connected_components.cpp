#include <iostream>
#include <stdexcept>

#include "algokit/graph.hpp"
#include "test_utils.hpp"

using namespace algokit;

void test_simple_graph()
{
    RUN_TEST("Simple Graph");

    Graph graph = Graph::undirected(6);

    graph.add_edge(0, 1);
    graph.add_edge(1, 2);
    graph.add_edge(3, 4);

    auto result = graph.connected_components();

    EXPECT_EQ(result.component_count(), 3);

    int c0 = result.component_id(0);
    int c3 = result.component_id(3);
    int c5 = result.component_id(5);

    // Same component
    EXPECT_EQ(result.component_id(1), c0);
    EXPECT_EQ(result.component_id(2), c0);

    // Same component
    EXPECT_EQ(result.component_id(4), c3);

    // Different components
    EXPECT_TRUE(c0 != c3);
    EXPECT_TRUE(c0 != c5);
    EXPECT_TRUE(c3 != c5);

    PASS_TEST("Simple Graph");
}

void test_connected_graph()
{
    RUN_TEST("Connected Graph");

    Graph graph = Graph::undirected(5);

    graph.add_edge(0, 1);
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);

    auto result = graph.connected_components();

    EXPECT_EQ(result.component_count(), 1);

    int component = result.component_id(0);

    for (std::size_t i = 1; i < graph.vertex_count(); ++i)
    {
        EXPECT_EQ(result.component_id(i), component);
    }

    PASS_TEST("Connected Graph");
}

void test_single_vertex()
{
    RUN_TEST("Single Vertex");

    Graph graph = Graph::undirected(1);

    auto result = graph.connected_components();

    EXPECT_EQ(result.component_count(), 1);
    EXPECT_EQ(result.component_id(0), result.component_id(0));

    PASS_TEST("Single Vertex");
}

void test_empty_graph()
{
    RUN_TEST("Empty Graph");

    Graph graph = Graph::undirected(0);

    auto result = graph.connected_components();

    EXPECT_EQ(result.component_count(), 0);

    PASS_TEST("Empty Graph");
}

void test_directed_graph()
{
    RUN_TEST("Directed Graph");

    Graph graph = Graph::directed(3);

    EXPECT_THROW(
        graph.connected_components(),
        std::logic_error
    );

    PASS_TEST("Directed Graph");
}

int main()
{
    std::cout
        << "=====================================\n"
        << "AlgoKit Connected Components Tests\n"
        << "=====================================\n\n";

    test_simple_graph();
    test_connected_graph();
    test_single_vertex();
    test_empty_graph();
    test_directed_graph();

    std::cout
        << "\n=====================================\n"
        << "All tests passed!\n"
        << "=====================================\n";

    return 0;
}
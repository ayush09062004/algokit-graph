#include <iostream>
#include <stdexcept>

#include "algokit/graph.hpp"
#include "test_utils.hpp"

using namespace algokit;

//--------------------------------------------------
// Simple Directed Cycle
//--------------------------------------------------

void test_simple_cycle()
{
    RUN_TEST("Simple Directed Cycle");

    Graph graph = Graph::directed(3);

    graph.add_edge(0, 1);
    graph.add_edge(1, 2);
    graph.add_edge(2, 0);

    EXPECT_TRUE(graph.has_directed_cycle());

    PASS_TEST("Simple Directed Cycle");
}

//--------------------------------------------------
// Directed Acyclic Graph
//--------------------------------------------------

void test_dag()
{
    RUN_TEST("Directed Acyclic Graph");

    Graph graph = Graph::directed(5);

    graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(1, 3);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);

    EXPECT_TRUE(!graph.has_directed_cycle());

    PASS_TEST("Directed Acyclic Graph");
}

//--------------------------------------------------
// Disconnected Graph
//--------------------------------------------------

void test_disconnected_graph()
{
    RUN_TEST("Disconnected Graph");

    Graph graph = Graph::directed(6);

    graph.add_edge(0, 1);
    graph.add_edge(1, 2);

    graph.add_edge(3, 4);
    graph.add_edge(4, 5);
    graph.add_edge(5, 3);

    EXPECT_TRUE(graph.has_directed_cycle());

    PASS_TEST("Disconnected Graph");
}

//--------------------------------------------------
// Single Vertex
//--------------------------------------------------

void test_single_vertex()
{
    RUN_TEST("Single Vertex");

    Graph graph = Graph::directed(1);

    EXPECT_TRUE(!graph.has_directed_cycle());

    PASS_TEST("Single Vertex");
}

//--------------------------------------------------
// Empty Graph
//--------------------------------------------------

void test_empty_graph()
{
    RUN_TEST("Empty Graph");

    Graph graph = Graph::directed(0);

    EXPECT_TRUE(!graph.has_directed_cycle());

    PASS_TEST("Empty Graph");
}

//--------------------------------------------------
// Undirected Graph
//--------------------------------------------------

void test_undirected_graph()
{
    RUN_TEST("Undirected Graph");

    Graph graph = Graph::undirected(3);

    EXPECT_THROW(
        graph.has_directed_cycle(),
        std::logic_error
    );

    PASS_TEST("Undirected Graph");
}

int main()
{
    std::cout
        << "=====================================\n"
        << "AlgoKit Directed Cycle Detection Tests\n"
        << "=====================================\n\n";

    test_simple_cycle();
    test_dag();
    test_disconnected_graph();
    test_single_vertex();
    test_empty_graph();
    test_undirected_graph();

    std::cout
        << "\n=====================================\n"
        << "All tests passed!\n"
        << "=====================================\n";

    return 0;
}
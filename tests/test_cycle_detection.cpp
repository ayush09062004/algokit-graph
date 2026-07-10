#include <iostream>
#include <stdexcept>

#include "algokit/graph.hpp"
#include "test_utils.hpp"

using namespace algokit;

//--------------------------------------------------
// Simple Cycle
//--------------------------------------------------

void test_simple_cycle()
{
    RUN_TEST("Simple Cycle");

    Graph graph = Graph::undirected(3);

    graph.add_edge(0, 1);
    graph.add_edge(1, 2);
    graph.add_edge(2, 0);

    EXPECT_TRUE(graph.has_cycle());

    PASS_TEST("Simple Cycle");
}

//--------------------------------------------------
// Tree
//--------------------------------------------------

void test_tree()
{
    RUN_TEST("Tree");

    Graph graph = Graph::undirected(5);

    graph.add_edge(0,1);
    graph.add_edge(1,2);
    graph.add_edge(1,3);
    graph.add_edge(3,4);

    EXPECT_TRUE(!graph.has_cycle());

    PASS_TEST("Tree");
}
void test_parallel_edges()
{
    RUN_TEST("Parallel Edges");

    Graph graph = Graph::undirected(2);

    graph.add_edge(0,1);

    graph.add_edge(0,1);

    EXPECT_FALSE(
        graph.has_cycle()
    );

    PASS_TEST("Parallel Edges");
}
//--------------------------------------------------
// Disconnected Graph
//--------------------------------------------------

void test_disconnected_graph()
{
    RUN_TEST("Disconnected Graph");

    Graph graph = Graph::undirected(6);

    graph.add_edge(0,1);
    graph.add_edge(1,2);

    graph.add_edge(3,4);
    graph.add_edge(4,5);
    graph.add_edge(5,3);

    EXPECT_TRUE(graph.has_cycle());

    PASS_TEST("Disconnected Graph");
}

//--------------------------------------------------
// Single Vertex
//--------------------------------------------------

void test_single_vertex()
{
    RUN_TEST("Single Vertex");

    Graph graph = Graph::undirected(1);

    EXPECT_TRUE(!graph.has_cycle());

    PASS_TEST("Single Vertex");
}

//--------------------------------------------------
// Empty Graph
//--------------------------------------------------

void test_empty_graph()
{
    RUN_TEST("Empty Graph");

    Graph graph = Graph::undirected(0);

    EXPECT_TRUE(!graph.has_cycle());

    PASS_TEST("Empty Graph");
}

//--------------------------------------------------
// Directed Graph
//--------------------------------------------------

void test_directed_graph()
{
    RUN_TEST("Directed Graph");

    Graph graph = Graph::directed(3);

    EXPECT_THROW(
        graph.has_cycle(),
        std::logic_error
    );

    PASS_TEST("Directed Graph");
}

int main()
{
    std::cout
        << "=====================================\n"
        << "AlgoKit Cycle Detection Tests\n"
        << "=====================================\n\n";
    //test_parallel_edges();
    test_simple_cycle();
    test_tree();
    test_disconnected_graph();
    test_single_vertex();
    test_empty_graph();
    test_directed_graph();

    std::cout
        << "\n=====================================\n"
        << "All tests passed!\n"
        << "=====================================\n";

    return 0;
}
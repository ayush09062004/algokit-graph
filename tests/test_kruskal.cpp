#include <iostream>
#include <stdexcept>

#include "algokit/graph.hpp"
#include "test_utils.hpp"

using namespace algokit;

//--------------------------------------------------
// Simple Graph
//--------------------------------------------------

void test_simple_graph()
{
    RUN_TEST("Simple Graph");

    Graph graph = Graph::undirected(4);

    graph.add_edge(0,1,1);
    graph.add_edge(0,2,4);
    graph.add_edge(1,2,2);
    graph.add_edge(1,3,5);
    graph.add_edge(2,3,3);

    auto mst = graph.kruskal();

    EXPECT_EQ(mst.edge_count(), 3);
    EXPECT_EQ(mst.total_weight(), 6.0);

    PASS_TEST("Simple Graph");
}

//--------------------------------------------------
// Disconnected Graph
//--------------------------------------------------

void test_disconnected_graph()
{
    RUN_TEST("Disconnected Graph");

    Graph graph = Graph::undirected(6);

    graph.add_edge(0,1,1);
    graph.add_edge(1,2,2);

    graph.add_edge(3,4,4);

    auto mst = graph.kruskal();

    EXPECT_EQ(mst.edge_count(), 3);
    EXPECT_EQ(mst.total_weight(), 7.0);

    PASS_TEST("Disconnected Graph");
}

//--------------------------------------------------
// Single Vertex
//--------------------------------------------------

void test_single_vertex()
{
    RUN_TEST("Single Vertex");

    Graph graph = Graph::undirected(1);

    auto mst = graph.kruskal();

    EXPECT_EQ(mst.edge_count(), 0);
    EXPECT_EQ(mst.total_weight(), 0.0);

    PASS_TEST("Single Vertex");
}

//--------------------------------------------------
// Empty Graph
//--------------------------------------------------

void test_empty_graph()
{
    RUN_TEST("Empty Graph");

    Graph graph = Graph::undirected(0);

    auto mst = graph.kruskal();

    EXPECT_EQ(mst.edge_count(), 0);
    EXPECT_EQ(mst.total_weight(), 0.0);

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
        graph.kruskal(),
        std::logic_error
    );

    PASS_TEST("Directed Graph");
}

//--------------------------------------------------
// Duplicate Edges
//--------------------------------------------------

void test_duplicate_edges()
{
    RUN_TEST("Duplicate Edges");

    Graph graph = Graph::undirected(3);

    graph.add_edge(0,1,10);
    graph.add_edge(0,1,2);

    graph.add_edge(1,2,1);

    auto mst = graph.kruskal();

    EXPECT_EQ(mst.edge_count(),2);
    EXPECT_EQ(mst.total_weight(),3.0);

    PASS_TEST("Duplicate Edges");
}

//--------------------------------------------------

int main()
{
    std::cout
        << "=====================================\n"
        << "AlgoKit Kruskal Tests\n"
        << "=====================================\n\n";

    test_simple_graph();
    test_disconnected_graph();
    test_single_vertex();
    test_empty_graph();
    test_directed_graph();
    test_duplicate_edges();

    std::cout
        << "\n=====================================\n";
    std::cout << "All tests passed!\n";
    std::cout << "=====================================\n";

    return 0;
}
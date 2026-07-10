#include <iostream>
#include <stdexcept>

#include "algokit/graph.hpp"
#include "test_utils.hpp"

using namespace algokit;

//--------------------------------------------------
// Graph Creation
//--------------------------------------------------

void test_graph_creation()
{
    RUN_TEST("Graph Creation");

    Graph directed = Graph::directed(5);

    EXPECT_TRUE(directed.is_directed());
    EXPECT_EQ(directed.vertex_count(), 5);
    EXPECT_EQ(directed.edge_count(), 0);

    Graph undirected = Graph::undirected(10);

    EXPECT_FALSE(undirected.is_directed());
    EXPECT_EQ(undirected.vertex_count(), 10);
    EXPECT_EQ(undirected.edge_count(), 0);

    PASS_TEST("Graph Creation");
}

//--------------------------------------------------
// Add Edge
//--------------------------------------------------

void test_add_edge()
{
    RUN_TEST("Add Edge");

    Graph graph = Graph::directed(4);

    graph.add_edge(0, 1);
    graph.add_edge(1, 2);

    EXPECT_EQ(graph.edge_count(), 2);

    EXPECT_EQ(graph.neighbors(0).size(), 1);
    EXPECT_EQ(graph.neighbors(1).size(), 1);
    EXPECT_EQ(graph.neighbors(2).size(), 0);

    PASS_TEST("Add Edge");
}

//--------------------------------------------------
// Add Weighted Edge
//--------------------------------------------------

void test_weighted_edge()
{
    RUN_TEST("Weighted Edge");

    Graph graph = Graph::directed(3);

    graph.add_edge(0, 1, 3.5);

    EXPECT_EQ(graph.neighbors(0).size(), 1);
    EXPECT_EQ(graph.neighbors(0)[0].weight, 3.5);

    PASS_TEST("Weighted Edge");
}

//--------------------------------------------------
// Bulk Add Edges
//--------------------------------------------------

void test_add_edges()
{
    RUN_TEST("Bulk Add Edges");

    Graph graph = Graph::undirected(5);

    graph.add_edges({
        {0,1,1},
        {1,2,1},
        {2,3,1},
        {3,4,1}
    });

    EXPECT_EQ(graph.edge_count(), 4);

    EXPECT_EQ(graph.neighbors(0).size(), 1);
    EXPECT_EQ(graph.neighbors(1).size(), 2);
    EXPECT_EQ(graph.neighbors(2).size(), 2);
    EXPECT_EQ(graph.neighbors(3).size(), 2);
    EXPECT_EQ(graph.neighbors(4).size(), 1);

    PASS_TEST("Bulk Add Edges");
}

//--------------------------------------------------
// Invalid Vertex
//--------------------------------------------------

void test_invalid_vertex()
{
    RUN_TEST("Invalid Vertex");

    Graph graph = Graph::directed(3);

    EXPECT_THROW(
        graph.add_edge(0, 3),
        std::out_of_range
    );

    EXPECT_THROW(
        graph.add_edge(5, 0),
        std::out_of_range
    );

    PASS_TEST("Invalid Vertex");
}

//--------------------------------------------------
// Transpose
//--------------------------------------------------

void test_transpose()
{
    RUN_TEST("Transpose");

    Graph graph = Graph::directed(3);

    graph.add_edge(0,1);
    graph.add_edge(1,2);

    Graph transpose = graph.transpose();

    EXPECT_TRUE(transpose.is_directed());

    EXPECT_EQ(transpose.edge_count(),2);

    EXPECT_EQ(transpose.neighbors(1)[0].to,0);

    EXPECT_EQ(transpose.neighbors(2)[0].to,1);

    PASS_TEST("Transpose");
}

//--------------------------------------------------
// Undirected Transpose
//--------------------------------------------------

void test_invalid_transpose()
{
    RUN_TEST("Invalid Transpose");

    Graph graph = Graph::undirected(3);

    EXPECT_THROW(
        graph.transpose(),
        std::logic_error
    );

    PASS_TEST("Invalid Transpose");
}

void test_add_adjacency_matrix()
{
    RUN_TEST("Adjacency Matrix");

    Graph graph = Graph::directed(4);

    graph.add_adjacency_matrix({

        {0,1,0,0},

        {0,0,2,0},

        {0,0,0,3},

        {0,0,0,0}

    });

    EXPECT_EQ(graph.edge_count(),3);

    auto result = graph.dijkstra(0);

    EXPECT_EQ(result.distance(3),6);

    PASS_TEST("Adjacency Matrix");
}

//--------------------------------------------------

int main()
{
    std::cout
        << "=====================================\n"
        << "AlgoKit Graph Tests\n"
        << "=====================================\n\n";

    test_graph_creation();
    test_add_edge();
    test_weighted_edge();
    test_add_edges();
    test_invalid_vertex();
    test_transpose();
    test_invalid_transpose();
    test_add_adjacency_matrix();

    std::cout
        << "\n=====================================\n";
    std::cout << "All tests passed!\n";
    std::cout << "=====================================\n";

    return 0;
}
#include <iostream>
#include <stdexcept>

#include "algokit/graph.hpp"
#include "test_utils.hpp"

using namespace algokit;

//--------------------------------------------------
// Multiple SCCs
//--------------------------------------------------

void test_multiple_scc()
{
    RUN_TEST("Multiple SCCs");

    Graph graph = Graph::directed(8);

    graph.add_edge(0,1);
    graph.add_edge(1,2);
    graph.add_edge(2,0);

    graph.add_edge(2,3);

    graph.add_edge(3,4);
    graph.add_edge(4,5);
    graph.add_edge(5,3);

    graph.add_edge(6,7);
    graph.add_edge(7,6);

    auto result =
        graph.strongly_connected_components();

    EXPECT_EQ(
        result.component_count(),
        3
    );

    auto c0 = result.component_id(0);
    auto c1 = result.component_id(1);
    auto c2 = result.component_id(2);

    EXPECT_EQ(c0,c1);
    EXPECT_EQ(c1,c2);

    auto c3 = result.component_id(3);
    auto c4 = result.component_id(4);
    auto c5 = result.component_id(5);

    EXPECT_EQ(c3,c4);
    EXPECT_EQ(c4,c5);

    auto c6 = result.component_id(6);
    auto c7 = result.component_id(7);

    EXPECT_EQ(c6,c7);

    EXPECT_TRUE(c0 != c3);
    EXPECT_TRUE(c0 != c6);
    EXPECT_TRUE(c3 != c6);

    PASS_TEST("Multiple SCCs");
}

//--------------------------------------------------
// Single SCC
//--------------------------------------------------

void test_single_scc()
{
    RUN_TEST("Single SCC");

    Graph graph = Graph::directed(4);

    graph.add_edge(0,1);
    graph.add_edge(1,2);
    graph.add_edge(2,3);
    graph.add_edge(3,0);

    auto result =
        graph.strongly_connected_components();

    EXPECT_EQ(
        result.component_count(),
        1
    );

    auto id =
        result.component_id(0);

    EXPECT_EQ(id,
        result.component_id(1));

    EXPECT_EQ(id,
        result.component_id(2));

    EXPECT_EQ(id,
        result.component_id(3));

    PASS_TEST("Single SCC");
}

//--------------------------------------------------
// DAG
//--------------------------------------------------

void test_dag()
{
    RUN_TEST("DAG");

    Graph graph = Graph::directed(5);

    graph.add_edge(0,1);
    graph.add_edge(1,2);
    graph.add_edge(2,3);
    graph.add_edge(3,4);

    auto result =
        graph.strongly_connected_components();

    EXPECT_EQ(
        result.component_count(),
        5
    );

    PASS_TEST("DAG");
}

//--------------------------------------------------
// Empty Graph
//--------------------------------------------------

void test_empty_graph()
{
    RUN_TEST("Empty Graph");

    Graph graph =
        Graph::directed(0);

    auto result =
        graph.strongly_connected_components();

    EXPECT_EQ(
        result.component_count(),
        0
    );

    PASS_TEST("Empty Graph");
}

//--------------------------------------------------
// Single Vertex
//--------------------------------------------------

void test_single_vertex()
{
    RUN_TEST("Single Vertex");

    Graph graph =
        Graph::directed(1);

    auto result =
        graph.strongly_connected_components();

    EXPECT_EQ(
        result.component_count(),
        1
    );

    EXPECT_EQ(
        result.component_id(0),
        0
    );

    PASS_TEST("Single Vertex");
}

//--------------------------------------------------
// Undirected Graph
//--------------------------------------------------

void test_undirected_graph()
{
    RUN_TEST("Undirected Graph");

    Graph graph =
        Graph::undirected(3);

    EXPECT_THROW(
        graph.strongly_connected_components(),
        std::logic_error
    );

    PASS_TEST("Undirected Graph");
}

//--------------------------------------------------

int main()
{
    std::cout
        << "=====================================\n"
        << "AlgoKit SCC Tests\n"
        << "=====================================\n\n";

    test_multiple_scc();
    test_single_scc();
    test_dag();
    test_empty_graph();
    test_single_vertex();
    test_undirected_graph();

    std::cout
        << "\n=====================================\n";
    std::cout
        << "All tests passed!\n";
    std::cout
        << "=====================================\n";

    return 0;
}
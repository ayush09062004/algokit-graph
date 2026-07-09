#include <iostream>
#include <unordered_map>
#include <stdexcept>

#include "algokit/graph.hpp"
#include "test_utils.hpp"

using namespace algokit;

//--------------------------------------------------
// Helper
//--------------------------------------------------

void verify_topological_order(
    const Graph& graph,
    const std::vector<std::size_t>& order)
{
    EXPECT_EQ(order.size(), graph.vertex_count());

    std::unordered_map<std::size_t, std::size_t> position;

    for (std::size_t i = 0; i < order.size(); ++i)
    {
        position[order[i]] = i;
    }

    for (std::size_t u = 0;
         u < graph.vertex_count();
         ++u)
    {
        for (const Edge& edge : graph.neighbors(u))
        {
            EXPECT_TRUE(
                position[u] < position[edge.to]
            );
        }
    }
}

//--------------------------------------------------
// Simple DAG
//--------------------------------------------------

void test_simple_dag()
{
    RUN_TEST("Simple DAG");

    Graph graph = Graph::directed(6);

    graph.add_edge(5,2);
    graph.add_edge(5,0);
    graph.add_edge(4,0);
    graph.add_edge(4,1);
    graph.add_edge(2,3);
    graph.add_edge(3,1);

    auto result = graph.kahn_topological_sort();

    verify_topological_order(
        graph,
        result.order()
    );

    PASS_TEST("Simple DAG");
}

//--------------------------------------------------
// Linear Graph
//--------------------------------------------------

void test_linear_graph()
{
    RUN_TEST("Linear Graph");

    Graph graph = Graph::directed(5);

    graph.add_edge(0,1);
    graph.add_edge(1,2);
    graph.add_edge(2,3);
    graph.add_edge(3,4);

    auto result = graph.kahn_topological_sort();

    verify_topological_order(
        graph,
        result.order()
    );

    PASS_TEST("Linear Graph");
}

//--------------------------------------------------
// Empty Graph
//--------------------------------------------------

void test_empty_graph()
{
    RUN_TEST("Empty Graph");

    Graph graph = Graph::directed(0);

    auto result = graph.kahn_topological_sort();

    EXPECT_EQ(
        result.order().size(),
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

    Graph graph = Graph::directed(1);

    auto result = graph.kahn_topological_sort();

    EXPECT_EQ(
        result.order().size(),
        1
    );

    EXPECT_EQ(
        result.order()[0],
        0
    );

    PASS_TEST("Single Vertex");
}

//--------------------------------------------------
// Cyclic Graph
//--------------------------------------------------

void test_cyclic_graph()
{
    RUN_TEST("Cyclic Graph");

    Graph graph = Graph::directed(3);

    graph.add_edge(0,1);
    graph.add_edge(1,2);
    graph.add_edge(2,0);

    EXPECT_THROW(
        graph.kahn_topological_sort(),
        std::logic_error
    );

    PASS_TEST("Cyclic Graph");
}

//--------------------------------------------------
// Undirected Graph
//--------------------------------------------------

void test_undirected_graph()
{
    RUN_TEST("Undirected Graph");

    Graph graph = Graph::undirected(3);

    EXPECT_THROW(
        graph.kahn_topological_sort(),
        std::logic_error
    );

    PASS_TEST("Undirected Graph");
}

//--------------------------------------------------

int main()
{
    std::cout
        << "=====================================\n"
        << "AlgoKit Kahn Topological Sort Tests\n"
        << "=====================================\n\n";

    test_simple_dag();
    test_linear_graph();
    test_empty_graph();
    test_single_vertex();
    test_cyclic_graph();
    test_undirected_graph();

    std::cout
        << "\n=====================================\n"
        << "All tests passed!\n"
        << "=====================================\n";

    return 0;
}
#include "algokit/bfs.hpp"
#include "algokit/graph.hpp"

#include "test_utils.hpp"

using namespace algokit;

int main()
{
    print_header("AlgoKit BFS Tests");

    //-------------------------------
    // Test 1
    //-------------------------------

    RUN_TEST("Simple Directed Graph")

    {
        Graph graph = Graph::directed(5);

        graph.add_edge(0,1);
        graph.add_edge(0,2);
        graph.add_edge(2,3);

        BFSResult result = bfs(graph,0);

        EXPECT_EQ(result.distance()[0],0);
        EXPECT_EQ(result.distance()[1],1);
        EXPECT_EQ(result.distance()[2],1);
        EXPECT_EQ(result.distance()[3],2);

        EXPECT_EQ(result.parent()[0],-1);
        EXPECT_EQ(result.parent()[1],0);
        EXPECT_EQ(result.parent()[2],0);
        EXPECT_EQ(result.parent()[3],2);
    }

    PASS_TEST("Simple Directed Graph")

    //-------------------------------
    // Test 2
    //-------------------------------

    RUN_TEST("Disconnected Graph")

    {
        Graph graph = Graph::directed(5);

        graph.add_edge(0,1);

        BFSResult result = bfs(graph,0);

        EXPECT_EQ(result.distance()[4],-1);
    }

    PASS_TEST("Disconnected Graph")

    //-------------------------------
    // Test 3
    //-------------------------------

    RUN_TEST("Single Vertex")

    {
        Graph graph = Graph::directed(1);

        BFSResult result = bfs(graph,0);

        EXPECT_EQ(result.distance()[0],0);
    }

    PASS_TEST("Single Vertex")

    //-------------------------------
    // Test 4
    //-------------------------------

    RUN_TEST("Invalid Source")

    {
        Graph graph = Graph::directed(5);

        EXPECT_THROW(
            bfs(graph,100),
            std::out_of_range
        );
    }

    PASS_TEST("Invalid Source")

    print_success();

    return 0;
}
#include "algokit/graph.hpp"

#include "test_utils.hpp"

using namespace algokit;

int main()
{
    print_header("AlgoKit DFS Tests");

    //--------------------------------------------------
    // Test 1
    //--------------------------------------------------

    RUN_TEST("Simple Directed Graph")

    {
        Graph graph = Graph::directed(4);

        graph.add_edge(0,1);
        graph.add_edge(0,2);
        graph.add_edge(1,3);

        DFSResult result = graph.dfs(0);

        EXPECT_EQ(result.order()[0],0);
        EXPECT_EQ(result.order()[1],1);
        EXPECT_EQ(result.order()[2],3);
        EXPECT_EQ(result.order()[3],2);

        EXPECT_EQ(result.parent()[0],-1);
        EXPECT_EQ(result.parent()[1],0);
        EXPECT_EQ(result.parent()[2],0);
        EXPECT_EQ(result.parent()[3],1);

        EXPECT_EQ(result.discovery_time()[0],0);
        EXPECT_EQ(result.discovery_time()[1],1);
        EXPECT_EQ(result.discovery_time()[2],5);
        EXPECT_EQ(result.discovery_time()[3],2);

        EXPECT_EQ(result.finish_time()[0],7);
        EXPECT_EQ(result.finish_time()[1],4);
        EXPECT_EQ(result.finish_time()[2],6);
        EXPECT_EQ(result.finish_time()[3],3);
    }

    PASS_TEST("Simple Directed Graph");

    //--------------------------------------------------
    // Test 2
    //--------------------------------------------------

    RUN_TEST("Disconnected Graph")

    {
        Graph graph = Graph::directed(4);

        graph.add_edge(0,1);
        graph.add_edge(2,3);

        DFSResult result = graph.dfs(0);

        EXPECT_EQ(result.discovery_time()[2],-1);
        EXPECT_EQ(result.discovery_time()[3],-1);

        EXPECT_EQ(result.finish_time()[2],-1);
        EXPECT_EQ(result.finish_time()[3],-1);
    }

    PASS_TEST("Disconnected Graph");

    //--------------------------------------------------
    // Test 3
    //--------------------------------------------------

    RUN_TEST("Single Vertex")

    {
        Graph graph = Graph::directed(1);

        DFSResult result = graph.dfs(0);

        EXPECT_EQ(result.order()[0],0);

        EXPECT_EQ(result.parent()[0],-1);

        EXPECT_EQ(result.discovery_time()[0],0);

        EXPECT_EQ(result.finish_time()[0],1);
    }

    PASS_TEST("Single Vertex");

    //--------------------------------------------------
    // Test 4
    //--------------------------------------------------

    RUN_TEST("Invalid Source")

    {
        Graph graph = Graph::directed(5);

        EXPECT_THROW(
            graph.dfs(100),
            std::out_of_range
        );
    }

    PASS_TEST("Invalid Source");

    print_success();

    return 0;
}
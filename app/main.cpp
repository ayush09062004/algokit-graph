#include <iostream>

#include "algokit/graph.hpp"

int main()
{
    using namespace algokit;

    Graph graph = Graph::directed(5);

    graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(2, 4, 3.5);

    std::cout << "Vertices : "
              << graph.vertex_count()
              << '\n';

    std::cout << "Edges : "
              << graph.edge_count()
              << '\n';

    std::cout << "Directed : "
              << std::boolalpha
              << graph.is_directed()
              << '\n';

    std::cout << "\nNeighbors of 0\n";

    for (const auto& edge : graph.neighbors(0))
    {
        std::cout
            << edge.to
            << " (weight = "
            << edge.weight
            << ")\n";
    }

    return 0;
}
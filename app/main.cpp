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

    Graph graph2 = Graph::undirected(6);

    graph2.add_edge(0, 1);
    graph2.add_edge(1, 2);

    graph2.add_edge(3, 4);

    auto result = graph2.connected_components();

    std::cout << "Connected Components\n";
    std::cout << "--------------------\n";

    std::cout << "Component Count : "
              << result.component_count()
              << "\n\n";

    for (std::size_t i = 0; i < graph2.vertex_count(); ++i)
    {
        std::cout
            << "Vertex "
            << i
            << " -> Component "
            << result.component_id(i)
            << '\n';
    }

    std::cout << "\nComponents\n";

    for (const auto& component : result.components())
    {
        std::cout << "{ ";

        for (std::size_t vertex : component)
        {
            std::cout << vertex << " ";
        }

        std::cout << "}\n";
    }

    return 0;
}
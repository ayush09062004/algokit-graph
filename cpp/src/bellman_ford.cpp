#include "algokit/bellman_ford.hpp"

#include "algokit/graph.hpp"
#include "algokit/types.hpp"

#include <stdexcept>
#include <utility>
#include <vector>

namespace algokit {

ShortestPathResult
bellman_ford(
    const Graph& graph,
    std::size_t source)
{
    graph.neighbors(source);

    std::size_t vertices = graph.vertex_count();

    std::vector<Weight> distance(
        vertices,
        INF
    );

    std::vector<int> parent(
        vertices,
        -1
    );

    distance[source] = 0.0;

    //--------------------------------------------------
    // Relax edges V-1 times
    //--------------------------------------------------

    for (std::size_t i = 1; i < vertices; ++i)
    {
        bool updated = false;

        for (const GraphEdge& edge : graph.edges())
        {
            if (distance[edge.from] == INF)
            {
                continue;
            }

            Weight candidate =
                distance[edge.from] + edge.weight;

            if (candidate >= distance[edge.to])
            {
                continue;
            }

            distance[edge.to] = candidate;

            parent[edge.to] =
                static_cast<int>(edge.from);

            updated = true;
        }

        //--------------------------------------------------
        // Early stopping
        //--------------------------------------------------

        if (!updated)
        {
            break;
        }
    }

    //--------------------------------------------------
    // Detect reachable negative cycle
    //--------------------------------------------------

    for (const GraphEdge& edge : graph.edges())
    {
        if (distance[edge.from] == INF)
        {
            continue;
        }

        if (distance[edge.from] + edge.weight <
            distance[edge.to])
        {
            throw std::logic_error(
                "Bellman-Ford detected a reachable negative-weight cycle."
            );
        }
    }

    return ShortestPathResult(
        std::move(distance),
        std::move(parent)
    );
}

} // namespace algokit
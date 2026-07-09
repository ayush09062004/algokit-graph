#include "algokit/shortest_path.hpp"

#include "algokit/graph.hpp"

#include <limits>
#include <queue>
#include <vector>

namespace algokit {

ShortestPathResult
shortest_path(
    const Graph& graph,
    std::size_t source)
{
    graph.neighbors(source);

    std::vector<Weight> distance(
        graph.vertex_count(),
        std::numeric_limits<Weight>::infinity()
    );

    std::vector<int> parent(
        graph.vertex_count(),
        -1
    );

    std::queue<std::size_t> queue;

    distance[source] = 0.0;

    queue.push(source);

    while (!queue.empty())
    {
        std::size_t current = queue.front();

        queue.pop();

        for (const Edge& edge : graph.neighbors(current))
        {
            if (distance[edge.to] !=
                std::numeric_limits<Weight>::infinity())
            {
                continue;
            }

            distance[edge.to] =
                distance[current] + 1.0;

            parent[edge.to] =
                static_cast<int>(current);

            queue.push(edge.to);
        }
    }

    return ShortestPathResult(
        std::move(distance),
        std::move(parent)
    );
}

} // namespace algokit
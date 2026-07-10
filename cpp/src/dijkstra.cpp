#include "algokit/dijkstra.hpp"

#include "algokit/graph.hpp"
#include "algokit/types.hpp"

#include <functional>
#include <queue>
#include <utility>
#include <vector>

namespace algokit {

ShortestPathResult
dijkstra(
    const Graph& graph,
    std::size_t source)
{
    graph.neighbors(source);

    std::vector<Weight> distance(
        graph.vertex_count(),
        INF
    );

    std::vector<int> parent(
        graph.vertex_count(),
        -1
    );

    using Node = std::pair<Weight, std::size_t>;

    std::priority_queue<
        Node,
        std::vector<Node>,
        std::greater<Node>
    > priority_queue;

    distance[source] = 0.0;

    priority_queue.push({0.0, source});

    while (!priority_queue.empty())
    {
        auto [current_distance, current] =
            priority_queue.top();

        priority_queue.pop();

        //--------------------------------------------------
        // Ignore stale entries
        //--------------------------------------------------

        if (current_distance > distance[current])
        {
            continue;
        }

        //--------------------------------------------------
        // Relax outgoing edges
        //--------------------------------------------------

        for (const Edge& edge : graph.neighbors(current))
        {
            Weight new_distance =
                current_distance + edge.weight;

            if (new_distance >= distance[edge.to])
            {
                continue;
            }

            distance[edge.to] = new_distance;

            parent[edge.to] =
                static_cast<int>(current);

            priority_queue.push(
                {
                    new_distance,
                    edge.to
                }
            );
        }
    }

    return ShortestPathResult(
        std::move(distance),
        std::move(parent)
    );
}

} // namespace algokit
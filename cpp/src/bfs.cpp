#include "algokit/bfs.hpp"

#include <queue>

namespace algokit {

BFSResult bfs(
    const Graph& graph,
    std::size_t source)
{
    graph.neighbors(source);
    std::vector<std::size_t> order;
    std::vector<int> distance(
        graph.vertex_count(),
        -1);

    std::vector<int> parent(
        graph.vertex_count(),
        -1);

    std::queue<std::size_t> queue;

    queue.push(source);

    distance[source] = 0;

    while (!queue.empty())
    {
        std::size_t current = queue.front();

        queue.pop();

        order.push_back(current);

        for (const Edge& edge : graph.neighbors(current))
        {
            if (distance[edge.to] != -1)
            {
                continue;
            }

            distance[edge.to] =
                distance[current] + 1;

            parent[edge.to] = current;

            queue.push(edge.to);
        }
    }

    return BFSResult(
        std::move(order),
        std::move(distance),
        std::move(parent));
}

}
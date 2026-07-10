#include "algokit/prim.hpp"

#include "algokit/graph.hpp"

#include <queue>
#include <stdexcept>
#include <vector>

namespace algokit {

namespace
{

struct QueueEdge
{
    Weight weight;
    std::size_t from;
    std::size_t to;

    bool operator>(const QueueEdge& other) const
    {
        return weight > other.weight;
    }
};

} // namespace

MSTResult
prim(const Graph& graph)
{
    if (graph.is_directed())
    {
        throw std::logic_error(
            "Prim's algorithm is only supported for undirected graphs."
        );
    }

    const std::size_t vertices =
        graph.vertex_count();

    if (vertices == 0)
    {
        return MSTResult({}, 0.0);
    }

    std::vector<bool> visited(vertices, false);

    std::priority_queue<
        QueueEdge,
        std::vector<QueueEdge>,
        std::greater<QueueEdge>
    > pq;

    std::vector<GraphEdge> mst;

    Weight total_weight = 0.0;

    //--------------------------------------------------
    // Handle disconnected graphs
    //--------------------------------------------------

    for (std::size_t start = 0;
         start < vertices;
         ++start)
    {
        if (visited[start])
        {
            continue;
        }

        visited[start] = true;

        for (const auto& edge : graph.neighbors(start))
        {
            pq.push(
                {
                    edge.weight,
                    start,
                    edge.to
                });
        }

        while (!pq.empty())
        {
            QueueEdge current = pq.top();
            pq.pop();

            if (visited[current.to])
            {
                continue;
            }

            visited[current.to] = true;

            mst.push_back(
                {
                    current.from,
                    current.to,
                    current.weight
                });

            total_weight += current.weight;

            for (const auto& edge :
                 graph.neighbors(current.to))
            {
                if (!visited[edge.to])
                {
                    pq.push(
                        {
                            edge.weight,
                            current.to,
                            edge.to
                        });
                }
            }
        }
    }

    return MSTResult(
        std::move(mst),
        total_weight
    );
}

} // namespace algokit
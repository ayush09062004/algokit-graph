#include "algokit/kahn_topological_sort.hpp"

#include "algokit/graph.hpp"

#include <queue>
#include <stdexcept>
#include <vector>

namespace algokit {

KahnTopologicalSortResult
kahn_topological_sort(
    const Graph& graph)
{
    std::vector<int> indegree(
        graph.vertex_count(),
        0
    );

    //--------------------------------------------------
    // Compute indegree
    //--------------------------------------------------

    for (std::size_t u = 0;
         u < graph.vertex_count();
         ++u)
    {
        for (const Edge& edge : graph.neighbors(u))
        {
            ++indegree[edge.to];
        }
    }

    //--------------------------------------------------
    // Initialize queue
    //--------------------------------------------------

    std::queue<std::size_t> queue;

    for (std::size_t vertex = 0;
         vertex < graph.vertex_count();
         ++vertex)
    {
        if (indegree[vertex] == 0)
        {
            queue.push(vertex);
        }
    }

    //--------------------------------------------------
    // Kahn's Algorithm
    //--------------------------------------------------

    std::vector<std::size_t> order;

    while (!queue.empty())
    {
        std::size_t current = queue.front();
        queue.pop();

        order.push_back(current);

        for (const Edge& edge : graph.neighbors(current))
        {
            --indegree[edge.to];

            if (indegree[edge.to] == 0)
            {
                queue.push(edge.to);
            }
        }
    }

    //--------------------------------------------------
    // Cycle Check
    //--------------------------------------------------

    if (order.size() != graph.vertex_count())
    {
        throw std::logic_error(
            "Topological sort is only defined for DAGs."
        );
    }

    return KahnTopologicalSortResult(
        std::move(order)
    );
}

} // namespace algokit
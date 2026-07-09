#include "algokit/topological_sort.hpp"

#include "algokit/directed_cycle_detection.hpp"
#include "algokit/graph.hpp"

#include <algorithm>
#include <stdexcept>
#include <vector>

namespace algokit {

namespace {

void dfs(
    const Graph& graph,
    std::size_t current,
    std::vector<bool>& visited,
    std::vector<std::size_t>& order)
{
    visited[current] = true;

    for (const Edge& edge : graph.neighbors(current))
    {
        if (!visited[edge.to])
        {
            dfs(
                graph,
                edge.to,
                visited,
                order
            );
        }
    }

    order.push_back(current);
}

} // anonymous namespace

TopologicalSortResult
topological_sort(const Graph& graph)
{
    if (has_directed_cycle(graph))
    {
        throw std::logic_error(
            "Topological sort is only defined for DAGs."
        );
    }

    std::vector<bool> visited(
        graph.vertex_count(),
        false
    );

    std::vector<std::size_t> order;

    for (std::size_t vertex = 0;
         vertex < graph.vertex_count();
         ++vertex)
    {
        if (!visited[vertex])
        {
            dfs(
                graph,
                vertex,
                visited,
                order
            );
        }
    }

    std::reverse(
        order.begin(),
        order.end()
    );

    return TopologicalSortResult(
        std::move(order)
    );
}

} // namespace algokit
#include "algokit/cycle_detection.hpp"
#include "algokit/graph.hpp"

#include <vector>

namespace algokit {

namespace {

bool dfs_has_cycle(
    const Graph& graph,
    std::size_t current,
    int parent,
    std::vector<bool>& visited)
{
    visited[current] = true;

    for (const Edge& edge : graph.neighbors(current))
    {
        std::size_t neighbor = edge.to;

        if (!visited[neighbor])
        {
            if (dfs_has_cycle(
                    graph,
                    neighbor,
                    static_cast<int>(current),
                    visited))
            {
                return true;
            }
        }
        else if (static_cast<int>(neighbor) != parent)
        {
            return true;
        }
    }

    return false;
}

} // anonymous namespace

bool has_cycle(const Graph& graph)
{
    std::vector<bool> visited(graph.vertex_count(), false);

    for (std::size_t vertex = 0;
         vertex < graph.vertex_count();
         ++vertex)
    {
        if (visited[vertex])
        {
            continue;
        }

        if (dfs_has_cycle(
                graph,
                vertex,
                -1,
                visited))
        {
            return true;
        }
    }

    return false;
}

} // namespace algokit
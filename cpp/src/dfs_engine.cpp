#include "algokit/internal/dfs_engine.hpp"

namespace algokit::internal {

DFSState::DFSState(std::size_t vertices)
    : visited(vertices, false),
      parent(vertices, -1),
      discovery_time(vertices, -1),
      finish_time(vertices, -1)
{
}

void dfs_visit(
    const Graph& graph,
    std::size_t current,
    DFSState& state)
{
    state.visited[current] = true;

    state.discovery_time[current] = state.timer++;

    state.order.push_back(current);

    for (const Edge& edge : graph.neighbors(current))
    {
        if (state.visited[edge.to])
        {
            continue;
        }

        state.parent[edge.to] = static_cast<int>(current);

        dfs_visit(graph, edge.to, state);
    }

    state.finish_time[current] = state.timer++;
}

} // namespace algokit::internal
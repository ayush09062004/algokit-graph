#include "algokit/dfs.hpp"

namespace algokit {

namespace {

struct DFSState
{
    std::vector<bool> visited;
    std::vector<int> parent;
    std::vector<int> discovery_time;
    std::vector<int> finish_time;
    std::vector<std::size_t> order;

    int timer = 0;

    explicit DFSState(std::size_t vertices)
        : visited(vertices, false),
          parent(vertices, -1),
          discovery_time(vertices, -1),
          finish_time(vertices, -1)
    {
    }
};

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

        state.parent[edge.to] = current;

        dfs_visit(graph, edge.to, state);
    }

    state.finish_time[current] = state.timer++;
}

} // anonymous namespace

DFSResult dfs(
    const Graph& graph,
    std::size_t source)
{
    graph.neighbors(source);

    DFSState state(graph.vertex_count());

    dfs_visit(graph, source, state);

    return DFSResult(
        std::move(state.order),
        std::move(state.parent),
        std::move(state.discovery_time),
        std::move(state.finish_time)
    );
}

} // namespace algokit
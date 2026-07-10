#include "algokit/dfs.hpp"
#include "algokit/internal/dfs_engine.hpp"

#include <utility>

namespace algokit {

DFSResult dfs(
    const Graph& graph,
    std::size_t source)
{
    graph.neighbors(source);
    internal::DFSState state(graph.vertex_count());

    internal::dfs_visit(graph, source, state);

    return DFSResult(
        std::move(state.order),
        std::move(state.parent),
        std::move(state.discovery_time),
        std::move(state.finish_time)
    );
}

} // namespace algokit
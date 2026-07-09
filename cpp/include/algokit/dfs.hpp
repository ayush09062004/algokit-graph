#pragma once

#include <cstddef>

#include "algokit/dfs_result.hpp"
#include "algokit/graph.hpp"

namespace algokit {

DFSResult dfs(
    const Graph& graph,
    std::size_t source
);

} // namespace algokit
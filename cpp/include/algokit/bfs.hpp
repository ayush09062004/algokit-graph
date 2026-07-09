#pragma once

#include <cstddef>

#include "algokit/bfs_result.hpp"
#include "algokit/graph.hpp"

namespace algokit {

BFSResult bfs(
    const Graph& graph,
    std::size_t source
);

}
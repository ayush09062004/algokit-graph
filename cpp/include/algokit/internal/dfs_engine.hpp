#pragma once

#include <cstddef>
#include <vector>

#include "algokit/graph.hpp"

namespace algokit::internal {

struct DFSState
{
    std::vector<bool> visited;

    std::vector<int> parent;

    std::vector<int> discovery_time;

    std::vector<int> finish_time;

    std::vector<std::size_t> order;

    int timer = 0;

    explicit DFSState(std::size_t vertices);
};

void dfs_visit(
    const Graph& graph,
    std::size_t current,
    DFSState& state
);

} // namespace algokit::internal
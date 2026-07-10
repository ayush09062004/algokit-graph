#pragma once

#include "algokit/shortest_path_result.hpp"

namespace algokit {

class Graph;

/**
 * @brief Computes shortest paths using Bellman-Ford.
 *
 * Supports negative edge weights.
 * Throws std::logic_error if a reachable negative-weight cycle exists.
 */
ShortestPathResult bellman_ford(
    const Graph& graph,
    std::size_t source
);

} // namespace algokit
#pragma once

#include "algokit/shortest_path_result.hpp"

namespace algokit {

class Graph;

/**
 * @brief Computes shortest paths from a source vertex in an
 * unweighted graph using Breadth First Search.
 *
 * @param graph Input graph.
 * @param source Source vertex.
 *
 * @return ShortestPathResult
 */
ShortestPathResult shortest_path(
    const Graph& graph,
    std::size_t source
);

} // namespace algokit
#pragma once

#include "algokit/shortest_path_result.hpp"

namespace algokit {

class Graph;

/**
 * @brief Computes shortest paths from a source vertex using
 * Dijkstra's algorithm.
 *
 * @param graph Input weighted graph.
 * @param source Source vertex.
 *
 * @return ShortestPathResult
 */
ShortestPathResult dijkstra(
    const Graph& graph,
    std::size_t source
);

} // namespace algokit
#pragma once

namespace algokit {

class Graph;

/**
 * @brief Detects whether a directed graph contains a cycle.
 *
 * @param graph Input graph.
 *
 * @return true if a directed cycle exists.
 * @return false otherwise.
 */
bool has_directed_cycle(const Graph& graph);

} // namespace algokit
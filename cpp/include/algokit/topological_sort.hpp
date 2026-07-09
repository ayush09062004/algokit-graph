#pragma once

#include "algokit/topological_sort_result.hpp"

namespace algokit {

class Graph;

TopologicalSortResult
topological_sort(const Graph& graph);

} // namespace algokit
#pragma once

#include "algokit/kahn_topological_sort_result.hpp"

namespace algokit {

class Graph;

KahnTopologicalSortResult
kahn_topological_sort(
    const Graph& graph
);

} // namespace algokit
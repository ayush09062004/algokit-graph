#pragma once

#include "algokit/mst_result.hpp"

namespace algokit {

class Graph;

MSTResult kruskal(
    const Graph& graph
);

} // namespace algokit
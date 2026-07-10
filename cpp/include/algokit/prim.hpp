#pragma once

#include "algokit/mst_result.hpp"

namespace algokit {

class Graph;

MSTResult prim(
    const Graph& graph
);

} // namespace algokit
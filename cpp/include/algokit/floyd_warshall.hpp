#pragma once

#include "algokit/floyd_warshall_result.hpp"

namespace algokit {

class Graph;

FloydWarshallResult
floyd_warshall(
    const Graph& graph
);

} // namespace algokit
#pragma once

#include "algokit/strongly_connected_components_result.hpp"

namespace algokit {

class Graph;

StronglyConnectedComponentsResult
strongly_connected_components(
    const Graph& graph
);

}
#pragma once

#include "algokit/connected_components_result.hpp"
#include "algokit/graph.hpp"

namespace algokit {

ConnectedComponentsResult connected_components(
    const Graph& graph
);

} // namespace algokit
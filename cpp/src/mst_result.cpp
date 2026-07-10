#include "algokit/mst_result.hpp"

#include <utility>

namespace algokit {

MSTResult::MSTResult(
    std::vector<GraphEdge> edges,
    Weight total_weight)
    : edges_(std::move(edges)),
      total_weight_(total_weight)
{
}

Weight
MSTResult::total_weight() const
{
    return total_weight_;
}

std::size_t
MSTResult::edge_count() const
{
    return edges_.size();
}

const std::vector<GraphEdge>&
MSTResult::edges() const
{
    return edges_;
}

} // namespace algokit
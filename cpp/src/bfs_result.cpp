#include "algokit/bfs_result.hpp"

namespace algokit {

BFSResult::BFSResult(
    std::vector<std::size_t> order,
    std::vector<int> distance,
    std::vector<int> parent
)
    : order_(std::move(order)),
      distance_(std::move(distance)),
      parent_(std::move(parent))
{
}

const std::vector<std::size_t>& BFSResult::order() const
{
    return order_;
}

const std::vector<int>& BFSResult::distance() const
{
    return distance_;
}

const std::vector<int>& BFSResult::parent() const
{
    return parent_;
}

}
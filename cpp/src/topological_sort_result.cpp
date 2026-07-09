#include "algokit/topological_sort_result.hpp"

#include <utility>

namespace algokit {

TopologicalSortResult::TopologicalSortResult(
    std::vector<std::size_t> order)
    : order_(std::move(order))
{
}

const std::vector<std::size_t>&
TopologicalSortResult::order() const
{
    return order_;
}

} // namespace algokit
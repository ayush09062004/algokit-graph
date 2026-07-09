#include "algokit/kahn_topological_sort_result.hpp"

#include <utility>

namespace algokit {

KahnTopologicalSortResult::KahnTopologicalSortResult(
    std::vector<std::size_t> order)
    : order_(std::move(order))
{
}

const std::vector<std::size_t>&
KahnTopologicalSortResult::order() const
{
    return order_;
}

} // namespace algokit
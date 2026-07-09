#include "algokit/dfs_result.hpp"

#include <utility>

namespace algokit {

DFSResult::DFSResult(
    std::vector<std::size_t> order,
    std::vector<int> parent,
    std::vector<int> discovery_time,
    std::vector<int> finish_time
)
    : order_(std::move(order)),
      parent_(std::move(parent)),
      discovery_time_(std::move(discovery_time)),
      finish_time_(std::move(finish_time))
{
}

const std::vector<std::size_t>& DFSResult::order() const
{
    return order_;
}

const std::vector<int>& DFSResult::parent() const
{
    return parent_;
}

const std::vector<int>& DFSResult::discovery_time() const
{
    return discovery_time_;
}

const std::vector<int>& DFSResult::finish_time() const
{
    return finish_time_;
}

} // namespace algokit
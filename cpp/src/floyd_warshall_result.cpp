#include "algokit/floyd_warshall_result.hpp"

#include <stdexcept>

namespace algokit {

FloydWarshallResult::FloydWarshallResult(
    std::vector<std::vector<Weight>> distance,
    std::vector<std::vector<int>> next)
    : distance_(std::move(distance)),
      next_(std::move(next))
{
}

Weight
FloydWarshallResult::distance(
    std::size_t from,
    std::size_t to) const
{
    return distance_.at(from).at(to);
}

bool
FloydWarshallResult::is_reachable(
    std::size_t from,
    std::size_t to) const
{
    return next_.at(from).at(to) != -1;
}

std::vector<std::size_t>
FloydWarshallResult::path(
    std::size_t from,
    std::size_t to) const
{
    if (!is_reachable(from, to))
    {
        return {};
    }

    std::vector<std::size_t> result;

    result.push_back(from);

    while (from != to)
    {
        from = static_cast<std::size_t>(
            next_[from][to]
        );

        result.push_back(from);
    }

    return result;
}

} // namespace algokit
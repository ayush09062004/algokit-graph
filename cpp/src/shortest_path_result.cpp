#include "algokit/shortest_path_result.hpp"

#include <algorithm>
#include <limits>
#include <stdexcept>
#include <utility>

namespace algokit {

ShortestPathResult::ShortestPathResult(
    std::vector<Weight> distance,
    std::vector<int> parent)
    : distance_(std::move(distance)),
      parent_(std::move(parent))
{
}

Weight
ShortestPathResult::distance(
    std::size_t vertex) const
{
    if (vertex >= distance_.size())
    {
        throw std::out_of_range(
            "Vertex index is out of range."
        );
    }

    return distance_[vertex];
}

int
ShortestPathResult::parent(
    std::size_t vertex) const
{
    if (vertex >= parent_.size())
    {
        throw std::out_of_range(
            "Vertex index is out of range."
        );
    }

    return parent_[vertex];
}

bool
ShortestPathResult::is_reachable(
    std::size_t vertex) const
{
    return distance(vertex) !=
        std::numeric_limits<Weight>::infinity();
}

std::vector<std::size_t>
ShortestPathResult::path_to(
    std::size_t vertex) const
{
    if (!is_reachable(vertex))
    {
        return {};
    }

    std::vector<std::size_t> path;

    int current = static_cast<int>(vertex);

    while (current != -1)
    {
        path.push_back(current);

        current = parent_[current];
    }

    std::reverse(
        path.begin(),
        path.end()
    );

    return path;
}

} // namespace algokit
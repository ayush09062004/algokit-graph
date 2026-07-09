#pragma once

#include <cstddef>
#include <vector>

#include "algokit/types.hpp"

namespace algokit {

class ShortestPathResult
{
public:

    ShortestPathResult(
        std::vector<Weight> distance,
        std::vector<int> parent
    );

    Weight distance(std::size_t vertex) const;

    int parent(std::size_t vertex) const;

    bool is_reachable(std::size_t vertex) const;

    std::vector<std::size_t> path_to(
        std::size_t vertex
    ) const;

private:

    std::vector<Weight> distance_;

    std::vector<int> parent_;
};

} // namespace algokit
#pragma once

#include <cstddef>
#include <vector>

#include "algokit/types.hpp"

namespace algokit {

class FloydWarshallResult
{
public:

    FloydWarshallResult(
        std::vector<std::vector<Weight>> distance,
        std::vector<std::vector<int>> next
    );

    Weight distance(
        std::size_t from,
        std::size_t to
    ) const;

    bool is_reachable(
        std::size_t from,
        std::size_t to
    ) const;

    std::vector<std::size_t> path(
        std::size_t from,
        std::size_t to
    ) const;

private:

    std::vector<std::vector<Weight>> distance_;

    std::vector<std::vector<int>> next_;
};

} // namespace algokit
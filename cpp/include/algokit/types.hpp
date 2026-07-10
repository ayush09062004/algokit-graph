#pragma once

#include <limits>

namespace algokit {

using Weight = double;

inline constexpr Weight INF =
    std::numeric_limits<Weight>::infinity();

struct Edge
{
    std::size_t to;
    Weight weight;
};

struct GraphEdge
{
    std::size_t from;
    std::size_t to;
    Weight weight;
};

} // namespace algokit
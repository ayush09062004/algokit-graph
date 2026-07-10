#pragma once

#include <limits>

namespace algokit {

using Weight = double;

inline constexpr Weight INF =
    std::numeric_limits<Weight>::infinity();

} // namespace algokit
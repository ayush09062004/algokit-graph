#pragma once

#include <vector>

#include "algokit/types.hpp"

namespace algokit {

class MSTResult
{
public:

    MSTResult(
        std::vector<GraphEdge> edges,
        Weight total_weight
    );

    Weight total_weight() const;

    std::size_t edge_count() const;

    const std::vector<GraphEdge>& edges() const;

private:

    std::vector<GraphEdge> edges_;

    Weight total_weight_;
};

} // namespace algokit
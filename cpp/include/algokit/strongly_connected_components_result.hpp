#pragma once

#include <cstddef>
#include <vector>

namespace algokit {

class StronglyConnectedComponentsResult
{
public:

    StronglyConnectedComponentsResult(
        std::vector<int> component_id,
        std::vector<std::vector<std::size_t>> components
    );

    std::size_t component_count() const;

    std::size_t component_id(
        std::size_t vertex
    ) const;

    const std::vector<
        std::vector<std::size_t>
    >& components() const;

private:

    std::vector<int> component_id_;

    std::vector<
        std::vector<std::size_t>
    > components_;
};

}
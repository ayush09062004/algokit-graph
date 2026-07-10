#pragma once

#include <cstddef>
#include <vector>

namespace algokit {

class ConnectedComponentsResult
{
public:

    ConnectedComponentsResult(
        std::vector<int> component_ids,
        std::vector<std::vector<std::size_t>> components
    );

    std::size_t component_count() const;

    int component_id(std::size_t vertex) const;

    const std::vector<int>&component_ids() const;

    const std::vector<std::vector<std::size_t>>&
    components() const;

private:

    std::vector<int> component_ids_;

    std::vector<std::vector<std::size_t>>
    components_;
};

} // namespace algokit
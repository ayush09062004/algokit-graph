#include <stdexcept>
#include <utility>
#include "algokit/connected_components_result.hpp" 
namespace algokit {

ConnectedComponentsResult::ConnectedComponentsResult(
    std::vector<int> component_ids,
    std::vector<std::vector<std::size_t>> components)
    : component_ids_(std::move(component_ids)),
      components_(std::move(components))
{
}

std::size_t
ConnectedComponentsResult::component_count() const
{
    return components_.size();
}

int ConnectedComponentsResult::component_id(
    std::size_t vertex) const
{
    if (vertex >= component_ids_.size())
    {
        throw std::out_of_range(
            "Vertex index is out of range."
        );
    }

    return component_ids_[vertex];
}

const std::vector<std::vector<std::size_t>>&
ConnectedComponentsResult::components() const
{
    return components_;
}

} // namespace algokit
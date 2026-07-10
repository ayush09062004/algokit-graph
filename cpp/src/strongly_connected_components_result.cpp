#include "algokit/strongly_connected_components_result.hpp"

#include <stdexcept>
#include <utility>

namespace algokit {

StronglyConnectedComponentsResult::
StronglyConnectedComponentsResult(
    std::vector<int> component_id,
    std::vector<std::vector<std::size_t>> components)
    : component_id_(std::move(component_id)),
      components_(std::move(components))
{
}

std::size_t
StronglyConnectedComponentsResult::
component_count() const
{
    return components_.size();
}

std::size_t
StronglyConnectedComponentsResult::
component_id(
    std::size_t vertex) const
{
    if (vertex >= component_id_.size())
    {
        throw std::out_of_range(
            "Vertex index is out of range."
        );
    }

    return component_id_[vertex];
}

const std::vector<int>&
StronglyConnectedComponentsResult::component_ids() const
{
    return component_id_;
}

const std::vector<
    std::vector<std::size_t>
>&
StronglyConnectedComponentsResult::
components() const
{
    return components_;
}

}
#include "algokit/disjoint_set.hpp"

#include <numeric>
#include <stdexcept>

namespace algokit {

//--------------------------------------------------
// Constructor
//--------------------------------------------------

DisjointSet::DisjointSet(std::size_t size)
    : parent_(size),
      size_(size, 1),
      component_count_(size)
{
    std::iota(
        parent_.begin(),
        parent_.end(),
        0
    );
}

//--------------------------------------------------
// Validation
//--------------------------------------------------

void DisjointSet::validate_vertex(
    std::size_t vertex
) const
{
    if (vertex >= parent_.size())
    {
        throw std::out_of_range(
            "Vertex index is out of range."
        );
    }
}

//--------------------------------------------------
// Find (Path Compression)
//--------------------------------------------------

std::size_t
DisjointSet::find(
    std::size_t vertex
)
{
    validate_vertex(vertex);

    if (parent_[vertex] != vertex)
    {
        parent_[vertex] =
            find(parent_[vertex]);
    }

    return parent_[vertex];
}

//--------------------------------------------------
// Union by Size
//--------------------------------------------------

bool
DisjointSet::unite(
    std::size_t u,
    std::size_t v
)
{
    u = find(u);
    v = find(v);

    if (u == v)
    {
        return false;
    }

    if (size_[u] < size_[v])
    {
        std::swap(u, v);
    }

    parent_[v] = u;

    size_[u] += size_[v];

    --component_count_;

    return true;
}

//--------------------------------------------------
// Connected
//--------------------------------------------------

bool
DisjointSet::connected(
    std::size_t u,
    std::size_t v
)
{
    return find(u) == find(v);
}

//--------------------------------------------------
// Component Size
//--------------------------------------------------

std::size_t
DisjointSet::component_size(
    std::size_t vertex
)
{
    return size_[find(vertex)];
}

//--------------------------------------------------
// Component Count
//--------------------------------------------------

std::size_t
DisjointSet::component_count() const
{
    return component_count_;
}

} // namespace algokit
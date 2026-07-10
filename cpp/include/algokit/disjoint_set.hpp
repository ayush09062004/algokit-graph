#pragma once

#include <cstddef>
#include <vector>

namespace algokit {

class DisjointSet
{
public:

    explicit DisjointSet(std::size_t size);

    std::size_t find(std::size_t vertex);

    bool unite(
        std::size_t u,
        std::size_t v
    );

    bool connected(
        std::size_t u,
        std::size_t v
    );

    std::size_t component_size(
        std::size_t vertex
    );

    std::size_t component_count() const;

private:

    void validate_vertex(
        std::size_t vertex
    ) const;

    std::vector<std::size_t> parent_;

    std::vector<std::size_t> size_;

    std::size_t component_count_;
};

} // namespace algokit
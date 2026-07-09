#pragma once

#include <cstddef>
#include <vector>

namespace algokit {

using Weight = double;

struct Edge {
    std::size_t to;
    Weight weight;
};

class Graph {
public:
    static Graph directed(std::size_t vertices);

    static Graph undirected(std::size_t vertices);

    void add_edge(
        std::size_t from,
        std::size_t to,
        Weight weight = 1.0
    );

    std::size_t vertex_count() const;

    std::size_t edge_count() const;

    bool is_directed() const;

    const std::vector<Edge>& neighbors(std::size_t vertex) const;

private:
    Graph(std::size_t vertices, bool directed);

    bool directed_;

    std::size_t vertex_count_;

    std::size_t edge_count_;

    std::vector<std::vector<Edge>> adjacency_list_;
};

} // namespace algokit
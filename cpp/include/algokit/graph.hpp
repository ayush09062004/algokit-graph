#pragma once

#include <cstddef>
#include <vector>
#include "algokit/dfs_result.hpp"
#include "algokit/bfs_result.hpp"
#include "algokit/connected_components_result.hpp"
#include "algokit/cycle_detection.hpp"
#include "algokit/directed_cycle_detection.hpp"
#include "algokit/topological_sort_result.hpp"
#include "algokit/kahn_topological_sort_result.hpp"
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

    BFSResult bfs(std::size_t source) const;

    DFSResult dfs(std::size_t source) const;

    ConnectedComponentsResult connected_components() const;

    bool has_cycle() const;

    bool has_directed_cycle() const;

    TopologicalSortResult topological_sort() const;

    KahnTopologicalSortResult
    kahn_topological_sort() const;

private:
    void validate_vertex(std::size_t vertex) const;
    Graph(std::size_t vertices, bool directed);

    bool directed_;

    std::size_t vertex_count_;

    std::size_t edge_count_;

    std::vector<std::vector<Edge>> adjacency_list_;
};

} // namespace algokit
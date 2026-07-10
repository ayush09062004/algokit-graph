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
#include "algokit/shortest_path_result.hpp"
#include "algokit/types.hpp"
#include "algokit/dijkstra.hpp"
#include "algokit/bellman_ford.hpp"
#include "algokit/floyd_warshall.hpp"
#include "algokit/floyd_warshall_result.hpp"
#include "algokit/mst_result.hpp"
#include "algokit/kruskal.hpp"
#include "algokit/prim.hpp"
namespace algokit {

//using Weight = double;


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

    const std::vector<GraphEdge>& edges() const;

    BFSResult bfs(std::size_t source) const;

    DFSResult dfs(std::size_t source) const;

    ConnectedComponentsResult connected_components() const;

    bool has_cycle() const;

    bool has_directed_cycle() const;

    TopologicalSortResult topological_sort() const;

    KahnTopologicalSortResult
    kahn_topological_sort() const;

    ShortestPathResult shortest_path(
    std::size_t source
    ) const;

    ShortestPathResult dijkstra(
    std::size_t source
    ) const;

    ShortestPathResult bellman_ford(
    std::size_t source
    ) const;

    FloydWarshallResult floyd_warshall() const;

    MSTResult kruskal() const;

    MSTResult prim() const;

private:
    void validate_vertex(std::size_t vertex) const;
    Graph(std::size_t vertices, bool directed);

    bool directed_;

    std::size_t vertex_count_;

    std::size_t edge_count_;

    std::vector<std::vector<Edge>> adjacency_list_;

    std::vector<GraphEdge> edges_;
};

} // namespace algokit
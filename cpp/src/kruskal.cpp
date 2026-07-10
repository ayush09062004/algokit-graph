#include "algokit/kruskal.hpp"

#include <algorithm>
#include <stdexcept>
#include <vector>

#include "algokit/disjoint_set.hpp"
#include "algokit/graph.hpp"

namespace algokit {

MSTResult
kruskal(
    const Graph& graph)
{
    if (graph.is_directed())
    {
        throw std::logic_error(
            "Kruskal's algorithm is only supported for undirected graphs."
        );
    }

    std::vector<GraphEdge> edges =
        graph.edges();

    std::sort(
        edges.begin(),
        edges.end(),
        [](
            const GraphEdge& a,
            const GraphEdge& b)
        {
            return a.weight < b.weight;
        });

    DisjointSet dsu(
        graph.vertex_count());

    std::vector<GraphEdge> mst;

    Weight total_weight = 0.0;

    for (const auto& edge : edges)
    {
        if (!dsu.unite(edge.from, edge.to))
        {
            continue;
        }

        mst.push_back(edge);

        total_weight += edge.weight;
    }

    return MSTResult(
        std::move(mst),
        total_weight
    );
}

} // namespace algokit
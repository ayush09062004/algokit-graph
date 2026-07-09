#include "algokit/graph.hpp"
#include <stdexcept>
#include "algokit/dfs.hpp"
#include "algokit/bfs.hpp"
#include "algokit/connected_components.hpp"
#include "algokit/cycle_detection.hpp"
#include "algokit/directed_cycle_detection.hpp"
#include "algokit/topological_sort.hpp"
#include "algokit/kahn_topological_sort.hpp"
#include "algokit/shortest_path.hpp"
namespace algokit {

//==========================
// Constructor
//==========================

Graph::Graph(std::size_t vertices, bool directed)
    : directed_(directed),
      vertex_count_(vertices),
      edge_count_(0),
      adjacency_list_(vertices)
{
}
void Graph::validate_vertex(std::size_t vertex) const
{
    if (vertex >= vertex_count_)
    {
        throw std::out_of_range(
            "Vertex index is out of range."
        );
    }
}
//==========================
// Factory Methods
//==========================

Graph Graph::directed(std::size_t vertices)
{
    return Graph(vertices, true);
}

Graph Graph::undirected(std::size_t vertices)
{
    return Graph(vertices, false);
}

//==========================
// Graph Operations
//==========================

void Graph::add_edge(
    std::size_t from,
    std::size_t to,
    Weight weight)
{
    validate_vertex(from);
    validate_vertex(to);
    adjacency_list_[from].push_back({to, weight});

    if (!directed_)
    {
        adjacency_list_[to].push_back({from, weight});
    }

    ++edge_count_;
}

//==========================
// Getters
//==========================

std::size_t Graph::vertex_count() const
{
    return vertex_count_;
}

std::size_t Graph::edge_count() const
{
    return edge_count_;
}

bool Graph::is_directed() const
{
    return directed_;
}

const std::vector<Edge>& Graph::neighbors(std::size_t vertex) const
{
    validate_vertex(vertex);
    return adjacency_list_[vertex];
}
BFSResult Graph::bfs(std::size_t source) const
{
    return algokit::bfs(*this, source);
}
DFSResult Graph::dfs(std::size_t source) const
{
    return algokit::dfs(*this, source);
}
ConnectedComponentsResult
Graph::connected_components() const
{
    if (directed_)
    {
        throw std::logic_error(
            "Connected components are only defined for undirected graphs."
        );
    }

    return algokit::connected_components(*this);
}

bool Graph::has_cycle() const
{
    if (directed_)
    {
        throw std::logic_error(
            "Cycle detection is currently supported only for undirected graphs."
        );
    }

    return algokit::has_cycle(*this);
}

bool Graph::has_directed_cycle() const
{
    if (!directed_)
    {
        throw std::logic_error(
            "Directed cycle detection is only supported for directed graphs."
        );
    }

    return algokit::has_directed_cycle(*this);
}

TopologicalSortResult
Graph::topological_sort() const
{
    if (!directed_)
    {
        throw std::logic_error(
            "Topological sort is only supported for directed graphs."
        );
    }

    return algokit::topological_sort(*this);
}

KahnTopologicalSortResult
Graph::kahn_topological_sort() const
{
    if (!directed_)
    {
        throw std::logic_error(
            "Kahn's topological sort is only supported for directed graphs."
        );
    }

    return algokit::kahn_topological_sort(*this);
}

ShortestPathResult
Graph::shortest_path(
    std::size_t source) const
{
    return algokit::shortest_path(
        *this,
        source
    );
}

} // namespace algokit
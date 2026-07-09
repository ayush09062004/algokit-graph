#include "algokit/graph.hpp"

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
    return adjacency_list_[vertex];
}

} // namespace algokit
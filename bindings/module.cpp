#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <sstream>

#include "algokit/graph.hpp"
#include "algokit/disjoint_set.hpp"
#include "algokit/strongly_connected_components_result.hpp"

namespace py = pybind11;

using namespace algokit;

// Helper to format a vector for __repr__ (first few elements)
static std::string repr_vector(const std::vector<std::size_t>& v, size_t max_show = 5) {
    std::ostringstream out;
    out << "[";
    if (!v.empty()) {
        size_t n = std::min(v.size(), max_show);
        for (size_t i = 0; i < n; ++i) {
            if (i) out << ", ";
            out << v[i];
        }
        if (v.size() > max_show) out << ", ...";
    }
    out << "]";
    return out.str();
}

//==================================================
// Module
//==================================================

PYBIND11_MODULE(algokit, m)
{
    m.doc() = "AlgoKit Python Bindings";
    m.attr("__version__") = "1.0.0";

    //==================================================
    // BFS Result
    //==================================================

    py::class_<BFSResult>(m, "BFSResult", R"doc(
        Result of a Breadth‑First Search (BFS) traversal.

        Attributes:
            order (list[int]): Vertices in the order they were visited.
            distance (list[float]): Distance from the source to each vertex.
            parent (list[int]): Parent of each vertex in the BFS tree.
        )doc")
        .def("order", &BFSResult::order, "Returns the order of vertices visited.")
        .def("distance", &BFSResult::distance, "Returns the distance from the source to each vertex.")
        .def("parent", &BFSResult::parent, "Returns the parent of each vertex in the BFS tree.")
        .def("__repr__", [](const BFSResult& r) {
            auto order = r.order();
            std::ostringstream out;
            out << "BFSResult(order=" << repr_vector(order) << ")";
            return out.str();
        }, "Returns a concise representation of the BFS result.");

    //==================================================
    // DFS Result
    //==================================================

    py::class_<DFSResult>(m, "DFSResult", R"doc(
        Result of a Depth‑First Search (DFS) traversal.

        Attributes:
            order (list[int]): Vertices in the order they were visited.
            parent (list[int]): Parent of each vertex in the DFS forest.
            discovery_time (list[int]): Discovery time of each vertex.
            finish_time (list[int]): Finish time of each vertex.
        )doc")
        .def("order", &DFSResult::order, "Returns the order of vertices visited.")
        .def("parent", &DFSResult::parent, "Returns the parent of each vertex in the DFS forest.")
        .def("discovery_time", &DFSResult::discovery_time, "Returns the discovery time of each vertex.")
        .def("finish_time", &DFSResult::finish_time, "Returns the finish time of each vertex.")
        .def("__repr__", [](const DFSResult& r) {
            auto order = r.order();
            std::ostringstream out;
            out << "DFSResult(order=" << repr_vector(order) << ")";
            return out.str();
        }, "Returns a concise representation of the DFS result.");

    //==================================================
    // Connected Components Result
    //==================================================

    py::class_<ConnectedComponentsResult>(
        m,
        "ConnectedComponentsResult",
        R"doc(
        Result of connected components computation.

        Attributes:
            component_count (int): Number of connected components.
            component_id (vertex: int) -> int: Component ID of a single vertex.
            component_ids () -> list[int]: Returns the component ID for every vertex.
            components (list[list[int]]): List of vertices in each component.
        )doc")
        .def(
            "component_count",
            &ConnectedComponentsResult::component_count,
            "Returns the number of connected components."
        )
        .def(
            "component_id",
            &ConnectedComponentsResult::component_id,
            py::arg("vertex"),
            "Returns the component ID for each vertex."
        )
        .def(
            "component_ids",
            &ConnectedComponentsResult::component_ids,
            py::return_value_policy::reference_internal,
            "Returns the component ID for every vertex."
        )
        .def(
            "components",
            &ConnectedComponentsResult::components,
            "Returns a list of vertices belonging to each component."
        )
        .def("__repr__", [](const ConnectedComponentsResult& r) {
            std::ostringstream out;
            out << "ConnectedComponentsResult(component_count=" << r.component_count() << ")";
            return out.str();
        }, "Returns a concise representation of the connected components result.");

    //==================================================
    // Topological Sort Result
    //==================================================

    py::class_<TopologicalSortResult>(
        m,
        "TopologicalSortResult",
        R"doc(
        Result of a topological sort (DFS‑based).

        Attributes:
            order (list[int]): Topological ordering of vertices.
        )doc")
        .def(
            "order",
            &TopologicalSortResult::order,
            "Returns the topological order of vertices."
        )
        .def("__repr__", [](const TopologicalSortResult& r) {
            auto order = r.order();
            std::ostringstream out;
            out << "TopologicalSortResult(order=" << repr_vector(order) << ")";
            return out.str();
        }, "Returns a concise representation of the topological sort result.");

    //==================================================
    // Kahn Topological Sort Result
    //==================================================

    py::class_<KahnTopologicalSortResult>(
        m,
        "KahnTopologicalSortResult",
        R"doc(
        Result of Kahn's topological sort.

        Attributes:
            order (list[int]): Topological ordering of vertices.
        )doc")
        .def(
            "order",
            &KahnTopologicalSortResult::order,
            "Returns the topological order of vertices."
        )
        .def("__repr__", [](const KahnTopologicalSortResult& r) {
            auto order = r.order();
            std::ostringstream out;
            out << "KahnTopologicalSortResult(order=" << repr_vector(order) << ")";
            return out.str();
        }, "Returns a concise representation of the Kahn topological sort result.");

    //==================================================
    // Shortest Path Result (no __repr__ – query‑based)
    //==================================================

    py::class_<ShortestPathResult>(
        m,
        "ShortestPathResult",
        R"doc(
        Result of single‑source shortest path algorithms (Dijkstra, Bellman‑Ford).

        Attributes:
            distance (callable): Query distance to a vertex.
            parent (callable): Query parent of a vertex.
            is_reachable (callable): Check if a vertex is reachable from source.
            path_to (callable): Reconstruct shortest path to a given vertex.
        )doc")
        .def(
            "distance",
            &ShortestPathResult::distance,
            py::arg("vertex"),
            "Returns the distance from source to the given vertex."
        )
        .def(
            "parent",
            &ShortestPathResult::parent,
            py::arg("vertex"),
            "Returns the parent of the given vertex in the shortest path tree."
        )
        .def(
            "is_reachable",
            &ShortestPathResult::is_reachable,
            py::arg("vertex"),
            "Returns True if the given vertex is reachable from the source."
        )
        .def(
            "path_to",
            &ShortestPathResult::path_to,
            py::arg("vertex"),
            "Returns the shortest path from source to the given vertex as a list of vertices."
        );
    // No __repr__ – users should query with methods.

    //==================================================
    // Floyd‑Warshall Result (no __repr__ – query‑based)
    //==================================================

    py::class_<FloydWarshallResult>(
        m,
        "FloydWarshallResult",
        R"doc(
        Result of Floyd‑Warshall all‑pairs shortest path algorithm.

        Attributes:
            distance (callable): Query distance between two vertices.
            is_reachable (callable): Check if a vertex is reachable from another.
            path (callable): Reconstruct shortest path between two vertices.
        )doc")
        .def(
            "distance",
            &FloydWarshallResult::distance,
            py::arg("from_vertex"),
            py::arg("to_vertex"),
            "Returns the shortest distance from from_vertex to to_vertex."
        )
        .def(
            "is_reachable",
            &FloydWarshallResult::is_reachable,
            py::arg("from_vertex"),
            py::arg("to_vertex"),
            "Returns True if to_vertex is reachable from from_vertex."
        )
        .def(
            "path",
            &FloydWarshallResult::path,
            py::arg("from_vertex"),
            py::arg("to_vertex"),
            "Returns the shortest path from from_vertex to to_vertex as a list of vertices."
        );
    // No __repr__ – users should query with methods.

    //==================================================
    // Disjoint Set (Union‑Find)
    //==================================================

    py::class_<DisjointSet>(
        m,
        "DisjointSet",
        R"doc(
        Disjoint‑Set Union (Union‑Find) data structure with path compression and union by size.

        Supports efficient union and find operations on disjoint sets.
        )doc")
        .def(
            py::init<std::size_t>(),
            py::arg("n"),
            "Construct a disjoint set with n elements (0 to n-1)."
        )
        .def(
            "find",
            &DisjointSet::find,
            py::arg("x"),
            "Find the representative (root) of the set containing x."
        )
        .def(
            "unite",
            &DisjointSet::unite,
            py::arg("x"),
            py::arg("y"),
            "Union the sets containing x and y. Returns True if they were merged."
        )
        .def(
            "connected",
            &DisjointSet::connected,
            py::arg("x"),
            py::arg("y"),
            "Return True if x and y belong to the same set."
        )
        .def(
            "component_size",
            &DisjointSet::component_size,
            py::arg("x"),
            "Return the size of the set containing x."
        )
        .def(
            "component_count",
            &DisjointSet::component_count,
            "Return the total number of disjoint sets."
        )
        .def("__repr__", [](const DisjointSet& ds) {
            std::ostringstream out;
            out << "DisjointSet(components=" << ds.component_count() << ")";
            return out.str();
        }, "Returns a concise representation of the disjoint set.");

    //==================================================
    // Edge (for adjacency list)
    //==================================================

    py::class_<Edge>(
        m,
        "Edge",
        R"doc(
        Represents a directed edge in a graph (used in adjacency lists).

        Attributes:
            to_vertex (int): Destination vertex.
            weight (float): Edge weight.
        )doc")
        .def_readonly(
            "to_vertex",
            &Edge::to,
            "Destination vertex."
        )
        .def_readonly(
            "weight",
            &Edge::weight,
            "Edge weight."
        )
        .def(
            "__repr__",
            [](const Edge& e)
            {
                std::ostringstream out;
                out << "Edge(to_vertex=" << e.to
                    << ", weight=" << e.weight << ")";
                return out.str();
            },
            "Return a string representation of the edge."
        );

    //==================================================
    // GraphEdge (for explicit edges with source)
    //==================================================

    py::class_<GraphEdge>(
        m,
        "GraphEdge",
        R"doc(
        Represents a full graph edge including its source.

        Attributes:
            from_vertex (int): Source vertex.
            to_vertex (int): Destination vertex.
            weight (float): Edge weight.
        )doc")
        .def_readonly(
            "from_vertex",
            &GraphEdge::from,
            "Source vertex."
        )
        .def_readonly(
            "to_vertex",
            &GraphEdge::to,
            "Destination vertex."
        )
        .def_readonly(
            "weight",
            &GraphEdge::weight,
            "Edge weight."
        )
        .def(
            "__repr__",
            [](const GraphEdge& e)
            {
                std::ostringstream out;
                out << "GraphEdge(from_vertex=" << e.from
                    << ", to_vertex=" << e.to
                    << ", weight=" << e.weight << ")";
                return out.str();
            },
            "Return a string representation of the graph edge."
        );

    //==================================================
    // MST Result
    //==================================================

    py::class_<MSTResult>(
        m,
        "MSTResult",
        R"doc(
        Result of a Minimum Spanning Tree (MST) algorithm (Kruskal or Prim).

        Attributes:
            total_weight (float): Total weight of the MST.
            edge_count (int): Number of edges in the MST.
            edges (list[GraphEdge]): Edges that form the MST.
        )doc")
        .def(
            "total_weight",
            &MSTResult::total_weight,
            "Returns the total weight of the MST."
        )
        .def(
            "edge_count",
            &MSTResult::edge_count,
            "Returns the number of edges in the MST."
        )
        .def(
            "edges",
            &MSTResult::edges,
            "Returns the list of edges in the MST."
        )
        .def("__repr__", [](const MSTResult& r) {
            std::ostringstream out;
            out << "MSTResult(total_weight=" << r.total_weight()
                << ", edge_count=" << r.edge_count() << ")";
            return out.str();
        }, "Returns a concise representation of the MST result.");

    //==================================================
    // Strongly Connected Components Result
    //==================================================

    py::class_<StronglyConnectedComponentsResult>(
        m,
        "StronglyConnectedComponentsResult",
        R"doc(
        Result of strongly connected components (SCC) computation.

        Attributes:
            component_count (int): Number of SCCs.
            component_id (list[int]): Component ID for each vertex.
            component_ids () -> list[int]: Returns the component ID for every vertex.
            components (list[list[int]]): List of vertices in each SCC.
        )doc")
        .def(
            "component_count",
            &StronglyConnectedComponentsResult::component_count,
            "Returns the number of strongly connected components."
        )
        .def(
            "component_id",
            &StronglyConnectedComponentsResult::component_id,
            "Returns the component ID for each vertex."
        )
        .def(
            "component_ids",
            &StronglyConnectedComponentsResult::component_ids,
            "Returns the component ID for every vertex."
        )
        .def(
            "components",
            &StronglyConnectedComponentsResult::components,
            "Returns a list of vertices in each strongly connected component."
        )
        .def("__repr__", [](const StronglyConnectedComponentsResult& r) {
            std::ostringstream out;
            out << "StronglyConnectedComponentsResult(component_count=" << r.component_count() << ")";
            return out.str();
        }, "Returns a concise representation of the SCC result.");

    //==================================================
    // Graph
    //==================================================

    py::class_<Graph>(m, "Graph", R"doc(
        A weighted graph that can be directed or undirected.

        Supports both adjacency‑list and adjacency‑matrix representations.
        Provides algorithms for BFS, DFS, connected components, topological sort,
        shortest paths, MST, and strongly connected components.
        )doc")

        .def_static(
            "undirected",
            &Graph::undirected,
            py::arg("num_vertices"),
            "Create an undirected graph with the given number of vertices (0 to num_vertices-1)."
        )

        .def_static(
            "directed",
            &Graph::directed,
            py::arg("num_vertices"),
            "Create a directed graph with the given number of vertices (0 to num_vertices-1)."
        )

        .def(
            "edges",
            &Graph::edges,
            py::return_value_policy::reference_internal,
            "Returns a const reference to the list of all edges (GraphEdge)."
        )

        .def(
            "neighbors",
            &Graph::neighbors,
            py::arg("vertex"),
            py::return_value_policy::reference_internal,
            "Returns a const reference to the list of outgoing edges from the given vertex."
        )
        .def(
            "add_edge",
            &Graph::add_edge,
            py::arg("from_vertex"),
            py::arg("to_vertex"),
            py::arg("weight") = 1.0,
            "Add a single edge to the graph. Weight defaults to 1.0."
        )

        .def(
            "add_edges",
            [](
            Graph& graph,
            py::iterable iterable)
            {
                std::vector<GraphEdge> edges;

                for (auto item : iterable)
                {
                    py::tuple t =
                    py::cast<py::tuple>(item);

                    if (t.size() == 2)
                    {
                        edges.push_back({
                        t[0].cast<std::size_t>(),
                        t[1].cast<std::size_t>(),
                        1.0
                        });
                    }
                    else if (t.size() == 3)
                    {
                        edges.push_back({
                        t[0].cast<std::size_t>(),
                        t[1].cast<std::size_t>(),
                        t[2].cast<Weight>()
                        });
                    }
                    else
                    {
                        throw std::runtime_error(
                        "Each edge must contain either "
                        "(from_vertex, to_vertex) or (from_vertex, to_vertex, weight)."
                        );
                    }
                }

                graph.add_edges(edges);
            },
            py::arg("edges"),
            R"doc(
            Add multiple edges from an iterable.

            Each item must be a tuple of (from_vertex, to_vertex) or (from_vertex, to_vertex, weight).
            )doc"
        )
        .def(
            "add_adjacency_matrix",
            [](
                Graph& graph,
                py::iterable matrix)
            {
                std::vector<
                    std::vector<Weight>
                > adjacency;

                for (auto row_obj : matrix)
                {
                    py::iterable row =
                        py::cast<py::iterable>(row_obj);

                    std::vector<Weight> values;

                    for (auto value : row)
                    {
                        values.push_back(
                            py::cast<Weight>(value)
                        );
                    }

                    adjacency.push_back(values);
                }

                graph.add_adjacency_matrix(
                    adjacency
                );
            },
            py::arg("adjacency_matrix"),
            "Add edges defined by an adjacency matrix. Non‑zero entries (including negative) indicate edges."
        )

        .def(
            "vertex_count",
            &Graph::vertex_count,
            "Returns the number of vertices in the graph."
        )

        .def(
            "edge_count",
            &Graph::edge_count,
            "Returns the number of edges in the graph."
        )

        .def(
            "is_directed",
            &Graph::is_directed,
            "Returns True if the graph is directed, False if undirected."
        )

        .def(
            "bfs",
            &Graph::bfs,
            py::arg("source"),
            "Performs a Breadth‑First Search starting from the source vertex."
        )

        .def(
            "dfs",
            &Graph::dfs,
            py::arg("source"),
            "Performs a Depth‑First Search starting from the source vertex."
        )

        .def(
            "connected_components",
            &Graph::connected_components,
            "Finds all connected components in an undirected graph."
        )

        .def(
            "has_cycle",
            &Graph::has_cycle,
            "Returns True if the undirected graph contains a cycle."
        )

        .def(
            "has_directed_cycle",
            &Graph::has_directed_cycle,
            "Returns True if the directed graph contains a cycle (using DFS)."
        )

        .def(
            "topological_sort",
            &Graph::topological_sort,
            "Returns a topological ordering of the directed graph (DFS‑based)."
        )

        .def(
            "kahn_topological_sort",
            &Graph::kahn_topological_sort,
            "Returns a topological ordering using Kahn's algorithm."
        )

        .def(
            "shortest_path",
            &Graph::shortest_path,
            py::arg("source"),
            "Computes shortest paths from source (handles negative edge weights)."
        )

        .def(
            "dijkstra",
            &Graph::dijkstra,
            py::arg("source"),
            "Computes shortest paths from source using Dijkstra's algorithm (non‑negative weights)."
        )

        .def(
            "bellman_ford",
            &Graph::bellman_ford,
            py::arg("source"),
            "Computes shortest paths from source using Bellman‑Ford (handles negative edges)."
        )

        .def(
            "floyd_warshall",
            &Graph::floyd_warshall,
            "Computes all‑pairs shortest paths using Floyd‑Warshall."
        )

        .def(
            "kruskal",
            &Graph::kruskal,
            "Computes a Minimum Spanning Tree using Kruskal's algorithm (undirected graphs)."
        )

        .def(
            "prim",
            &Graph::prim,
            "Computes a Minimum Spanning Tree using Prim's algorithm (undirected graphs)."
        )

        .def(
            "transpose",
            &Graph::transpose,
            "Returns the transpose of a directed graph (reverses all edges)."
        )

        .def(
            "strongly_connected_components",
            &Graph::strongly_connected_components,
            "Finds strongly connected components using Kosaraju's algorithm."
        )
        .def(
            "__repr__",
            [](const Graph& g)
            {
                std::ostringstream out;
                out << "Graph(num_vertices=" << g.vertex_count()
                    << ", num_edges=" << g.edge_count()
                    << ", directed=" << (g.is_directed() ? "True" : "False") << ")";
                return out.str();
            },
            "Returns a string representation of the graph."
        );
}
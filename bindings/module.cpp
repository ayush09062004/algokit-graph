#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "algokit/graph.hpp"
#include "algokit/disjoint_set.hpp"
#include "algokit/strongly_connected_components_result.hpp"

namespace py = pybind11;

using namespace algokit;

//==================================================
// Module
//==================================================

PYBIND11_MODULE(algokit, m)
{
    m.doc() = "AlgoKit Python Bindings";

    //==================================================
    // BFS Result
    //==================================================

    py::class_<BFSResult>(m, "BFSResult")
        .def("order", &BFSResult::order)
        .def("distance", &BFSResult::distance)
        .def("parent", &BFSResult::parent);

    //==================================================
    // DFS Result
    //==================================================

    py::class_<DFSResult>(m, "DFSResult")
        .def("order", &DFSResult::order)
        .def("parent", &DFSResult::parent)
        .def("discovery_time", &DFSResult::discovery_time)
        .def("finish_time", &DFSResult::finish_time);

    //==================================================
    // Connected Components Result
    //==================================================

    py::class_<ConnectedComponentsResult>(
        m,
        "ConnectedComponentsResult"
    )
        .def(
            "component_count",
            &ConnectedComponentsResult::component_count
        )
        .def(
            "component_id",
            &ConnectedComponentsResult::component_id
        )
        .def(
            "components",
            &ConnectedComponentsResult::components
        );

    //==================================================
    // Topological Sort Result
    //==================================================

    py::class_<TopologicalSortResult>(
        m,
        "TopologicalSortResult"
    )
        .def(
            "order",
            &TopologicalSortResult::order
        );

    //==================================================
    // Kahn Topological Sort Result
    //==================================================

    py::class_<KahnTopologicalSortResult>(
        m,
        "KahnTopologicalSortResult"
    )
        .def(
            "order",
            &KahnTopologicalSortResult::order
        );

    //==================================================
    // Shortest Path Result
    //==================================================

    py::class_<ShortestPathResult>(
        m,
        "ShortestPathResult"
    )
        .def(
            "distance",
            &ShortestPathResult::distance
        )
        .def(
            "parent",
            &ShortestPathResult::parent
        )
        .def(
            "is_reachable",
            &ShortestPathResult::is_reachable
        )
        .def(
            "path_to",
            &ShortestPathResult::path_to
        );

    py::class_<FloydWarshallResult>(
        m,
        "FloydWarshallResult"
    )
        .def(
            "distance",
            &FloydWarshallResult::distance
        )
        .def(
            "is_reachable",
            &FloydWarshallResult::is_reachable
        )
        .def(
            "path",
            &FloydWarshallResult::path
        );


    py::class_<DisjointSet>(
        m,
        "DisjointSet"
    )

    .def(
        py::init<std::size_t>()
    )

    .def(
        "find",
        &DisjointSet::find
    )

    .def(
        "unite",
        &DisjointSet::unite
    )

    .def(
        "connected",
        &DisjointSet::connected
    )

    .def(
        "component_size",
        &DisjointSet::component_size
    )

    .def(
        "component_count",
        &DisjointSet::component_count
    );


    py::class_<Edge>(
    m,
    "Edge"
)

.def_readonly(
    "to_vertex",
    &Edge::to
)

.def_readonly(
    "weight",
    &Edge::weight
);



    py::class_<GraphEdge>(
        m,
        "GraphEdge"
    )

    .def_readonly(
        "from_vertex",
        &GraphEdge::from
    )

    .def_readonly(
        "to_vertex",
        &GraphEdge::to
    )

    .def_readonly(
        "weight",
        &GraphEdge::weight
    );
    
    py::class_<MSTResult>(
        m,
        "MSTResult"
    )

    .def(
        "total_weight",
        &MSTResult::total_weight
    )

    .def(
        "edge_count",
        &MSTResult::edge_count
    )

    .def(
        "edges",
        &MSTResult::edges
    );

    py::class_<StronglyConnectedComponentsResult>(
        m,
        "StronglyConnectedComponentsResult"
    )

    .def(
        "component_count",
        &StronglyConnectedComponentsResult::component_count
    )

    .def(
        "component_id",
        &StronglyConnectedComponentsResult::component_id
    )

    .def(
        "components",
        &StronglyConnectedComponentsResult::components
    );

    //==================================================
    // Graph
    //==================================================

    py::class_<Graph>(m, "Graph")

        .def_static(
            "directed",
            &Graph::directed
        )

        .def_static(
            "undirected",
            &Graph::undirected
        )

        .def(
            "edges",
            &Graph::edges,
            py::return_value_policy::reference_internal
        )

        .def(
            "neighbors",
            &Graph::neighbors,
            py::arg("vertex"),
            py::return_value_policy::reference_internal
        )
        .def(
            "add_edge",
            &Graph::add_edge,
            py::arg("from_vertex"),
            py::arg("to_vertex"),
            py::arg("weight") = 1.0
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
            }
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
    }
)

        .def(
            "vertex_count",
            &Graph::vertex_count
        )

        .def(
            "edge_count",
            &Graph::edge_count
        )

        .def(
            "is_directed",
            &Graph::is_directed
        )

        .def(
            "bfs",
            &Graph::bfs
        )

        .def(
            "dfs",
            &Graph::dfs
        )

        .def(
            "connected_components",
            &Graph::connected_components
        )

        .def(
            "has_cycle",
            &Graph::has_cycle
        )

        .def(
            "has_directed_cycle",
            &Graph::has_directed_cycle
        )

        .def(
            "topological_sort",
            &Graph::topological_sort
        )

        .def(
            "kahn_topological_sort",
            &Graph::kahn_topological_sort
        )

        .def(
            "shortest_path",
            &Graph::shortest_path
        )

        .def(
            "dijkstra",
            &Graph::dijkstra
        )

        .def(
            "bellman_ford",
            &Graph::bellman_ford
        )

        .def(
            "floyd_warshall",
            &Graph::floyd_warshall
        )

        .def(
            "kruskal",
            &Graph::kruskal
        )

        .def(
            "prim",
            &Graph::prim
        )

        .def(
            "transpose",
            &Graph::transpose,
            "Return the transpose of a directed graph."
        )

        .def(
            "strongly_connected_components",
            &Graph::strongly_connected_components
        );
}
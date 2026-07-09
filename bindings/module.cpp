#include <pybind11/pybind11.h>

#include "algokit/graph.hpp"

namespace py = pybind11;

using namespace algokit;

PYBIND11_MODULE(algokit, m)
{
    m.doc() = "AlgoKit Python Bindings";

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
            "add_edge",
            &Graph::add_edge,
            py::arg("from"),
            py::arg("to"),
            py::arg("weight") = 1.0
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
        );
}
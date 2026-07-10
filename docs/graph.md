# Graph

The `Graph` class is the core data structure of AlgoKit.

It supports:

- Directed graphs
- Undirected graphs
- Weighted graphs
- Unweighted graphs

Graphs are internally stored as an **adjacency list**, providing efficient traversal and memory usage for sparse graphs.

---

## Creating a Graph

### Directed Graph

```cpp
Graph graph = Graph::directed(5);
```

### Undirected Graph

```cpp
Graph graph = Graph::undirected(5);
```

---

## Adding Edges

Unweighted edge

```cpp
graph.add_edge(0, 1);
```

Weighted edge

```cpp
graph.add_edge(0, 1, 2.5);
```

`add_edge(from, to, weight = 1.0)` throws `std::out_of_range` if either
`from` or `to` is `>= vertex_count()`. For an undirected graph, a single
call inserts the edge into both adjacency lists internally.

### Bulk Edge Insertion

Add many edges at once from a list of `GraphEdge{from, to, weight}`:

```cpp
graph.add_edges({
    {0, 1, 1.0},
    {1, 2, 2.5},
    {2, 3, 1.0}
});
```

Equivalent to calling `add_edge` for each entry, but reserves capacity up
front.

### From an Adjacency Matrix

```cpp
std::vector<std::vector<Weight>> matrix = {
    {0, 1, 0},
    {0, 0, 2},
    {0, 0, 0}
};

graph.add_adjacency_matrix(matrix);
```

`matrix` must be square and match `vertex_count()`
(`std::invalid_argument` otherwise). A `0` entry means "no edge". For
directed graphs every non-zero cell is added as an edge; for undirected
graphs only the upper triangle (`j > i`) is read, since each such cell
already implies the symmetric edge — the matrix is assumed to be
symmetric for undirected graphs, and asymmetric input is not validated
or reported.

---

## Querying Graph Information

```cpp
graph.vertex_count();   // std::size_t

graph.edge_count();     // std::size_t, number of add_edge() calls made

graph.is_directed();    // bool
```

---

## Traversing Neighbors and Edges

```cpp
for (const auto& edge : graph.neighbors(0))
{
    std::cout
        << edge.to
        << " "
        << edge.weight
        << '\n';
}
```

`neighbors(vertex)` returns a `const std::vector<Edge>&` (each `Edge` has
`to` and `weight`) and throws `std::out_of_range` for an invalid vertex.

```cpp
for (const auto& edge : graph.edges())
{
    std::cout << edge.from << " -> " << edge.to << " (" << edge.weight << ")\n";
}
```

`edges()` returns every edge added via `add_edge`/`add_edges`/
`add_adjacency_matrix` as a flat `const std::vector<GraphEdge>&` (each
`GraphEdge` has `from`, `to`, `weight`). For undirected graphs this list
contains one entry per call to `add_edge`, not two — the reverse direction
is only materialized in the adjacency list, not in `edges()`.

## Transpose

```cpp
Graph reversed = graph.transpose();
```

Returns a new directed graph with every edge reversed. Only defined for
directed graphs; throws `std::logic_error` if called on an undirected
graph.

## Cycle Checks

```cpp
graph.has_cycle();           // undirected graphs only
graph.has_directed_cycle();  // directed graphs only
```

Each throws `std::logic_error` if called on a graph of the wrong kind
(`has_cycle` on a directed graph, or `has_directed_cycle` on an undirected
graph). See [Cycle Detection](cycles/cycle_detection.md) and
[Directed Cycle Detection](cycles/directed_cycle_detection.md) for details
and complexity.

---

## Complexity

| Operation | Complexity |
|------------|------------|
| Add Edge | O(1) amortized |
| Add Edges (n) | O(n) |
| Add Adjacency Matrix | O(V²) |
| Neighbors | O(degree(v)) |
| Edges | O(1) (returns existing storage) |
| Vertex Count | O(1) |
| Edge Count | O(1) |
| Transpose | O(V + E) |

---

## Python

```python
g = algokit.Graph.directed(5)

g.add_edge(0, 1)
g.add_edge(1, 2, 2.5)          # weighted

g.add_edges([(0, 1), (1, 2, 2.5)])   # 2- or 3-tuples

g.add_adjacency_matrix([
    [0, 1, 0],
    [0, 0, 2],
    [0, 0, 0]
])

print(g.vertex_count())
print(g.edge_count())
print(g.is_directed())
```

!!! note "Python bindings gap"
    `neighbors()`, `edges()`, and `transpose()` are available in C++ but
    are **not currently exposed** to Python — see the roadmap/bug tracker.
    Everything else on this page is available from Python.
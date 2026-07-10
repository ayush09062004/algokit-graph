# Kruskal's Algorithm

Computes a Minimum Spanning Tree using edge sorting and Disjoint Set Union.

---

## Complexity

```
O(E log E)
```

---

## C++

```cpp
auto mst = graph.kruskal();

mst.total_weight();    // Weight (double)
mst.edge_count();       // std::size_t
mst.edges();            // const std::vector<GraphEdge>&, each with .from, .to, .weight
```

`graph.kruskal()` throws `std::logic_error` if called on a directed graph.
If the graph is disconnected, `kruskal()` returns a **minimum spanning
forest**: `mst.edge_count()` will be less than `vertex_count() - 1`.

---

## Python

```python
mst = graph.kruskal()

print(mst.total_weight())
print(mst.edge_count())

for edge in mst.edges():
    print(edge.from_vertex, "->", edge.to_vertex, edge.weight)
```

---

## Applications

- Network design
- Road construction
- Clustering
# Prim's Algorithm

Computes a Minimum Spanning Tree using a priority queue.

---

## Complexity

```
O(E log V)
```

---

## C++

```cpp
auto mst = graph.prim();

mst.total_weight();    // Weight (double)
mst.edge_count();       // std::size_t
mst.edges();            // const std::vector<GraphEdge>&, each with .from, .to, .weight
```

`graph.prim()` throws `std::logic_error` if called on a directed graph.
Like `kruskal()`, it returns a minimum spanning **forest** (one tree per
connected component) if the graph is disconnected, so results are
equivalent to Kruskal's regardless of connectivity.

---

## Python

```python
mst = graph.prim()

print(mst.total_weight())
print(mst.edge_count())

for edge in mst.edges():
    print(edge.from_vertex, "->", edge.to_vertex, edge.weight)
```

---

## Applications

- Communication networks
- Electrical grids
- Infrastructure planning
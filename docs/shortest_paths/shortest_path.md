# Shortest Path (Unweighted)

Computes shortest paths in an unweighted graph using Breadth First Search.

---

## Complexity

```
O(V + E)
```

---

## C++

```cpp
auto path = graph.shortest_path(0);

path.distance(5);        // Weight (double), edge-count from source, INF if unreachable
path.parent(5);           // int, -1 if none
path.is_reachable(5);     // bool
path.path_to(5);          // std::vector<std::size_t>, empty if unreachable
```

`graph.shortest_path(source)` throws `std::out_of_range` if
`source >= vertex_count()`, and again from `distance()`/`parent()` for an
out-of-range `vertex` argument. Every edge is treated as weight 1
regardless of any weight passed to `add_edge` — for weighted shortest
paths use [`dijkstra`](dijkstra.md) or [`bellman_ford`](bellman_ford.md).

---

## Python

```python
sp = graph.shortest_path(0)

print(sp.distance(5))
print(sp.is_reachable(5))
print(sp.path_to(5))
```

---

## Applications

- Maze solving
- Routing
- Social networks
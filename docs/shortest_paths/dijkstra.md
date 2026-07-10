# Dijkstra

Computes shortest paths from a source vertex in graphs with non-negative edge weights.

---

## Complexity

```
O(E log V)
```

---

## C++

```cpp
auto result = graph.dijkstra(0);

result.distance(5);        // Weight (double), INF if unreachable
result.parent(5);           // int, -1 if none
result.is_reachable(5);     // bool
result.path_to(5);          // std::vector<std::size_t>, empty if unreachable
```

`graph.dijkstra(source)` throws `std::out_of_range` if
`source >= vertex_count()`. Negative edge weights are **not** detected or
rejected — Dijkstra will silently return incorrect distances if the graph
has a negative-weight edge. Use [`bellman_ford`](bellman_ford.md) when
negative weights are possible.

---

## Python

```python
result = graph.dijkstra(0)

print(result.distance(5))
print(result.path_to(5))
```

---

## Applications

- GPS navigation
- Network routing
- Path planning
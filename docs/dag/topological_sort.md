# Topological Sort

Computes a valid ordering of vertices in a Directed Acyclic Graph (DAG).

Implemented using DFS.

---

## Complexity

```
O(V + E)
```

---

## C++

```cpp
auto topo = graph.topological_sort();

topo.order();   // const std::vector<std::size_t>&
```

`graph.topological_sort()` throws `std::logic_error` if called on an
undirected graph, and again if the graph contains a directed cycle (it is
only defined for DAGs — it internally calls `has_directed_cycle()` first).

---

## Python

```python
topo = graph.topological_sort()

print(topo.order())
```

---

## Applications

- Task scheduling
- Build systems
- Course prerequisite planning
# Kahn's Algorithm

Computes a topological ordering using vertex indegrees.

---

## Complexity

```
O(V + E)
```

---

## C++

```cpp
auto topo = graph.kahn_topological_sort();

topo.order();   // const std::vector<std::size_t>&
```

`graph.kahn_topological_sort()` throws `std::logic_error` if called on an
undirected graph, or if the graph contains a directed cycle (detected when
fewer than `vertex_count()` vertices are dequeued). Unlike
[`topological_sort()`](topological_sort.md), this is iterative (indegree
counting + queue), not recursive.

---

## Python

```python
topo = graph.kahn_topological_sort()

print(topo.order())
```

---

## Applications

- Scheduling
- Dependency resolution
- Detecting cycles in DAGs
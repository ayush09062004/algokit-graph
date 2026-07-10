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
```

---

## Python

```python
graph.kahn_topological_sort()
```

---

## Applications

- Scheduling
- Dependency resolution
- Detecting cycles in DAGs
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

topo.order();
```

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
# Undirected Cycle Detection

Determines whether an undirected graph contains a cycle.

---

## Complexity

```
O(V + E)
```

---

## C++

```cpp
bool cycle = graph.has_cycle();
```

`graph.has_cycle()` throws `std::logic_error` if called on a directed
graph — use [`has_directed_cycle()`](directed_cycle_detection.md) instead.

!!! warning "Parallel edges"
    If two edges are added between the same pair of vertices (a
    multigraph), `has_cycle()` reports `true` even though there is no
    cycle in the usual simple-graph sense — the DFS sees a second path
    back to that neighbor and can't distinguish it from a real cycle.
    Avoid adding duplicate edges between the same pair if you rely on a
    strict cycle check.

---

## Python

```python
print(graph.has_cycle())
```

---

## Applications

- Tree verification
- Network validation
# Directed Cycle Detection

Detects cycles in directed graphs using DFS recursion states.

---

## Complexity

```
O(V + E)
```

---

## C++

```cpp
bool cycle = graph.has_directed_cycle();
```

`graph.has_directed_cycle()` throws `std::logic_error` if called on an
undirected graph — use [`has_cycle()`](cycle_detection.md) instead.

---

## Python

```python
print(graph.has_directed_cycle())
```

---

## Applications

- Dependency graphs
- Deadlock detection
- Build systems
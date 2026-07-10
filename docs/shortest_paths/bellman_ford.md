# Bellman-Ford

Computes shortest paths in graphs that may contain negative edge weights.

Detects negative-weight cycles.

---

## Complexity

```
O(VE)
```

---

## C++

```cpp
auto result = graph.bellman_ford(0);
```

---

## Python

```python
graph.bellman_ford(0)
```

---

## Applications

- Currency arbitrage
- Financial graphs
- Networks with negative costs
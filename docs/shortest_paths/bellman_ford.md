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

result.distance(5);        // Weight (double), INF if unreachable
result.parent(5);           // int, -1 if none
result.is_reachable(5);     // bool
result.path_to(5);          // std::vector<std::size_t>, empty if unreachable
```

`graph.bellman_ford(source)` throws `std::out_of_range` if
`source >= vertex_count()`, and `std::logic_error` if a reachable
negative-weight cycle is detected — in that case no result is returned.

---

## Python

```python
result = graph.bellman_ford(0)

print(result.distance(5))
print(result.path_to(5))

# Negative-weight cycle raises RuntimeError:
try:
    graph.bellman_ford(0)
except RuntimeError as e:
    print(e)
```

---

## Applications

- Currency arbitrage
- Financial graphs
- Networks with negative costs
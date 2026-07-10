# Floyd-Warshall

Computes shortest paths between every pair of vertices.

---

## Complexity

```
O(V³)
```

---

## C++

```cpp
auto fw = graph.floyd_warshall();

fw.distance(0, 5);        // Weight (double), INF if unreachable
fw.is_reachable(0, 5);    // bool
fw.path(0, 5);             // std::vector<std::size_t>, empty if unreachable
```

`graph.floyd_warshall()` throws `std::logic_error` if the graph contains a
negative-weight cycle (self-distance `distance(i, i) < 0` for some `i`).

!!! warning "Parallel edges"
    If more than one edge is added between the same ordered pair
    `(from, to)`, Floyd-Warshall's distance matrix is initialized from
    whichever edge was added **last**, not the minimum-weight one. Avoid
    parallel edges, or pre-collapse them to the minimum weight yourself,
    if you need correct results in that case.

---

## Python

```python
fw = graph.floyd_warshall()

print(fw.distance(0, 5))
print(fw.path(0, 5))
```

---

## Applications

- Network optimization
- Distance matrices
- Routing tables
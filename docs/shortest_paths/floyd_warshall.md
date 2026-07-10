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

fw.distance(0, 5);
```

---

## Python

```python
fw = graph.floyd_warshall()
```

---

## Applications

- Network optimization
- Distance matrices
- Routing tables
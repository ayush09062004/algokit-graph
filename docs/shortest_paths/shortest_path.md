# Shortest Path (Unweighted)

Computes shortest paths in an unweighted graph using Breadth First Search.

---

## Complexity

```
O(V + E)
```

---

## C++

```cpp
auto path = graph.shortest_path(0);

path.distance(5);

path.path_to(5);
```

---

## Python

```python
sp = graph.shortest_path(0)

print(sp.path_to(5))
```

---

## Applications

- Maze solving
- Routing
- Social networks
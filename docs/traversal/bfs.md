# Breadth First Search

## Complexity

Time

O(V+E)

Space

O(V)

---

## C++

```cpp
auto bfs = graph.bfs(0);

bfs.order();

bfs.distance();

bfs.parent();
```

---

## Python

```python
bfs = graph.bfs(0)

print(bfs.order())
```

---

## Applications

- Shortest path in unweighted graphs
- Level order traversal
- Connected components
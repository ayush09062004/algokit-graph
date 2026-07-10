# Depth First Search (DFS)

Depth First Search explores as deep as possible before backtracking.

AlgoKit's DFS computes:

- Traversal order
- Discovery time
- Finish time
- Parent tree

---

## Complexity

Time

```
O(V + E)
```

Space

```
O(V)
```

---

## C++

```cpp
auto dfs = graph.dfs(0);

dfs.order();

dfs.discovery_time();

dfs.finish_time();

dfs.parent();
```

---

## Python

```python
dfs = graph.dfs(0)

print(dfs.order())
```

---

## Applications

- Topological Sorting
- Cycle Detection
- Strongly Connected Components
- Bridges
- Articulation Points
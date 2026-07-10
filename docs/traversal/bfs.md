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

bfs.order();      // const std::vector<std::size_t>&, visitation order
bfs.distance();    // const std::vector<int>&, hop count from source, -1 if unreachable
bfs.parent();      // const std::vector<int>&, BFS-tree parent, -1 for source/unreached
```

`graph.bfs(source)` throws `std::out_of_range` if `source >= vertex_count()`.
Works on both directed and undirected graphs, and traverses edges by
following outgoing edges only (so on a directed graph it explores
reachability from `source`, not full connectivity).

---

## Python

```python
bfs = graph.bfs(0)

print(bfs.order())
print(bfs.distance())
print(bfs.parent())
```

---

## Applications

- Shortest path in unweighted graphs
- Level order traversal
- Connected components
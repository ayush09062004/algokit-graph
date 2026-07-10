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

dfs.order();            // const std::vector<std::size_t>&, visitation order
dfs.parent();            // const std::vector<int>&, DFS-tree parent, -1 for source/unreached
dfs.discovery_time();    // const std::vector<int>&, -1 if unreached
dfs.finish_time();       // const std::vector<int>&, -1 if unreached
```

`graph.dfs(source)` throws `std::out_of_range` if `source >= vertex_count()`.
Implemented with plain recursion (one stack frame per vertex along the
longest explored path), so it only visits vertices reachable from `source`
and does not guard against native call-stack overflow on very deep/long
graphs.

---

## Python

```python
dfs = graph.dfs(0)

print(dfs.order())
print(dfs.discovery_time())
print(dfs.finish_time())
print(dfs.parent())
```

---

## Applications

- Topological Sorting
- Cycle Detection
- Strongly Connected Components
- Bridges
- Articulation Points
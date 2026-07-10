# Connected Components

Connected Components identify groups of vertices connected by paths in an undirected graph.

---

## Complexity

```
O(V + E)
```

---

## C++

```cpp
auto cc = graph.connected_components();

cc.component_count();     // std::size_t
cc.component_id(0);       // int, index into cc.components()
cc.components();          // const std::vector<std::vector<std::size_t>>&
```

`graph.connected_components()` throws `std::logic_error` if called on a
directed graph — use
[`strongly_connected_components()`](strongly_connected_components.md)
instead. `component_id(vertex)` throws `std::out_of_range` for an invalid
vertex.

---

## Python

```python
cc = graph.connected_components()

print(cc.component_count())
print(cc.component_id(0))
print(cc.components())
```

---

## Applications

- Network analysis
- Clustering
- Graph partitioning
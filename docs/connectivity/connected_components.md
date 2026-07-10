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

cc.component_count();

cc.component_id(0);

cc.components();
```

---

## Python

```python
cc = graph.connected_components()

print(cc.component_count())
```

---

## Applications

- Network analysis
- Clustering
- Graph partitioning
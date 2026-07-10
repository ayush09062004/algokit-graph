# Strongly Connected Components

AlgoKit implements Kosaraju's Algorithm to compute strongly connected components in directed graphs.

---

## Complexity

```
O(V + E)
```

---

## C++

```cpp
auto scc = graph.strongly_connected_components();

scc.component_count();

scc.components();
```

---

## Python

```python
scc = graph.strongly_connected_components()

print(scc.components())
```

---

## Applications

- Compiler optimization
- Dependency analysis
- Social network analysis
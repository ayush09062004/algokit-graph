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

scc.component_count();          // std::size_t
scc.component_id(vertex);       // std::size_t, index into scc.components()
scc.components();               // const std::vector<std::vector<std::size_t>>&
```

`graph.strongly_connected_components()` throws `std::logic_error` if
called on an undirected graph. Components are returned in reverse
topological order of the condensation graph (i.e. a component with no
outgoing edges to other components in the original graph appears first).

---

## Python

```python
scc = graph.strongly_connected_components()

print(scc.component_count())
print(scc.component_id(0))
print(scc.components())
```

---

## Applications

- Compiler optimization
- Dependency analysis
- Social network analysis
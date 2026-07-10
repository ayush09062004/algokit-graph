# Graph

The `Graph` class is the core data structure of AlgoKit.

It supports:

- Directed graphs
- Undirected graphs
- Weighted graphs
- Unweighted graphs

Graphs are internally stored as an **adjacency list**, providing efficient traversal and memory usage for sparse graphs.

---

## Creating a Graph

### Directed Graph

```cpp
Graph graph = Graph::directed(5);
```

### Undirected Graph

```cpp
Graph graph = Graph::undirected(5);
```

---

## Adding Edges

Unweighted edge

```cpp
graph.add_edge(0, 1);
```

Weighted edge

```cpp
graph.add_edge(0, 1, 2.5);
```

---

## Querying Graph Information

```cpp
graph.vertex_count();

graph.edge_count();

graph.is_directed();
```

---

## Traversing Neighbors

```cpp
for (const auto& edge : graph.neighbors(0))
{
    std::cout
        << edge.to
        << " "
        << edge.weight
        << '\n';
}
```

---

## Complexity

| Operation | Complexity |
|------------|------------|
| Add Edge | O(1) |
| Neighbors | O(degree(v)) |
| Vertex Count | O(1) |
| Edge Count | O(1) |

---

## Python

```python
g = algokit.Graph.directed(5)

g.add_edge(0, 1)

print(g.vertex_count())
```
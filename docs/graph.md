# Graph

The Graph class represents a weighted graph.

Supported features:

- Directed graphs
- Undirected graphs
- Weighted edges

## Example

```cpp
Graph graph = Graph::undirected(5);

graph.add_edge(0,1);
graph.add_edge(0,2);
```

Complexities

| Operation | Complexity |
|------------|------------|
| add_edge | O(1) |
| neighbors | O(1) |
| vertex_count | O(1) |
| edge_count | O(1) |
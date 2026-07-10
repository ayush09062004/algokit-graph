# Python Bindings

## Graph

```python
graph = algokit.Graph.directed(5)
```

Algorithms

```python
graph.bfs()

graph.dfs()

graph.connected_components()

graph.strongly_connected_components()

graph.topological_sort()

graph.kahn_topological_sort()

graph.shortest_path()

graph.dijkstra()

graph.bellman_ford()

graph.floyd_warshall()

graph.kruskal()

graph.prim()
```

---

## Disjoint Set

```python
dsu = algokit.DisjointSet(10)

dsu.unite(0,1)

dsu.connected(0,1)
```
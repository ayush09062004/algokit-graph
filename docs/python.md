# Python Bindings

Every public C++ API in `algokit::Graph` is exposed to Python through
`pybind11`, with two current exceptions noted below. The Python API mirrors
the C++ API's method names and semantics (same exceptions map to Python
exceptions: `std::out_of_range` -> `IndexError`, `std::invalid_argument` ->
`ValueError`, `std::logic_error` -> `RuntimeError`).

## Graph

```python
import algokit

g = algokit.Graph.directed(5)     # algokit.Graph.undirected(5) for undirected
```

### Building a Graph

```python
g.add_edge(0, 1)          # unweighted (weight defaults to 1.0)
g.add_edge(1, 2, 2.5)     # weighted

# add_edge's arguments must be passed positionally: `from` is a reserved
# Python keyword, so g.add_edge(from=0, to=1) is a SyntaxError.

g.add_edges([
    (0, 1),          # 2-tuple: unweighted
    (1, 2, 2.5),     # 3-tuple: weighted
])

g.add_adjacency_matrix([
    [0, 1, 0],
    [0, 0, 2],
    [0, 0, 0],
])
```

### Inspecting a Graph

```python
g.vertex_count()   # int
g.edge_count()     # int
g.is_directed()    # bool
```

!!! note "Not yet bound"
    `neighbors(vertex)`, `edges()`, and `transpose()` exist in the C++ API
    but are not currently exposed to Python.

### Algorithms

```python
graph.bfs(source)                          # -> BFSResult
graph.dfs(source)                          # -> DFSResult
graph.connected_components()               # -> ConnectedComponentsResult (undirected only)
graph.strongly_connected_components()      # -> StronglyConnectedComponentsResult (directed only)
graph.has_cycle()                          # -> bool (undirected only)
graph.has_directed_cycle()                 # -> bool (directed only)
graph.topological_sort()                   # -> TopologicalSortResult (directed only, DFS-based)
graph.kahn_topological_sort()              # -> KahnTopologicalSortResult (directed only)
graph.shortest_path(source)                # -> ShortestPathResult (unweighted BFS shortest path)
graph.dijkstra(source)                     # -> ShortestPathResult (non-negative weights)
graph.bellman_ford(source)                 # -> ShortestPathResult (negative weights allowed)
graph.floyd_warshall()                     # -> FloydWarshallResult (all-pairs)
graph.kruskal()                            # -> MSTResult (undirected only)
graph.prim()                               # -> MSTResult (undirected only)
```

Calling a directed-only or undirected-only algorithm on the wrong graph
kind raises `RuntimeError` (mapped from `std::logic_error`).

## Result Objects

```python
bfs = graph.bfs(0)
bfs.order()           # list[int], visitation order
bfs.distance()         # list[int], -1 if unreachable
bfs.parent()           # list[int], -1 for source/unreached

dfs = graph.dfs(0)
dfs.order()
dfs.parent()
dfs.discovery_time()
dfs.finish_time()

cc = graph.connected_components()
cc.component_count()
cc.component_id(vertex)
cc.components()        # list[list[int]]

scc = graph.strongly_connected_components()
scc.component_count()
scc.component_id(vertex)
scc.components()

topo = graph.topological_sort()          # or graph.kahn_topological_sort()
topo.order()            # list[int]

sp = graph.dijkstra(0)  # same interface for shortest_path() / bellman_ford()
sp.distance(vertex)      # float, math.inf if unreachable
sp.parent(vertex)        # int, -1 if none
sp.is_reachable(vertex)  # bool
sp.path_to(vertex)       # list[int], [] if unreachable

fw = graph.floyd_warshall()
fw.distance(u, v)
fw.is_reachable(u, v)
fw.path(u, v)             # list[int], [] if unreachable

mst = graph.kruskal()     # or graph.prim()
mst.total_weight()
mst.edge_count()
mst.edges()               # list[GraphEdge]

edge = mst.edges()[0]
edge.from_vertex
edge.to_vertex
edge.weight
```

`bellman_ford()` and `floyd_warshall()` both raise `RuntimeError` if the
graph contains a reachable negative-weight cycle.

## Disjoint Set

```python
dsu = algokit.DisjointSet(10)

dsu.find(3)                # int, root of 3's set
dsu.unite(0, 1)             # bool, False if already in same set
dsu.connected(0, 1)         # bool
dsu.component_size(0)       # int, size of 0's set
dsu.component_count()       # int, number of disjoint sets remaining
```

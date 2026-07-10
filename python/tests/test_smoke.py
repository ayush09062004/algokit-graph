import sys

sys.path.append("build")

import algokit


def banner(title):
    print("\n" + "=" * 60)
    print(title)
    print("=" * 60)


# --------------------------------------------------
# Graph Creation
# --------------------------------------------------

banner("Graph Creation")

g = algokit.Graph.directed(5)

assert g.vertex_count() == 5
assert g.edge_count() == 0
assert g.is_directed()

print("✓ Graph creation passed")


# --------------------------------------------------
# Add Edge
# --------------------------------------------------

banner("Add Edge")

g.add_edge(0, 1)
g.add_edge(1, 2)

assert g.edge_count() == 2

print("✓ Add edge passed")


# --------------------------------------------------
# BFS
# --------------------------------------------------

banner("BFS")

bfs = g.bfs(0)

assert bfs.order() == [0, 1, 2]
assert bfs.distance()[2] == 2
assert bfs.parent()[2] == 1

print("Order:", bfs.order())
print("Distance:", bfs.distance())
print("Parent:", bfs.parent())

print("✓ BFS passed")


# --------------------------------------------------
# DFS
# --------------------------------------------------

banner("DFS")

dfs = g.dfs(0)

assert dfs.order() == [0, 1, 2]

print("Order:", dfs.order())
print("Discovery:", dfs.discovery_time())
print("Finish:", dfs.finish_time())

print("✓ DFS passed")


# --------------------------------------------------
# Connected Components
# --------------------------------------------------

banner("Connected Components")

ug = algokit.Graph.undirected(6)

ug.add_edge(0, 1)
ug.add_edge(1, 2)
ug.add_edge(3, 4)

cc = ug.connected_components()

assert cc.component_count() == 3

print("Component Count:", cc.component_count())
print("Components:", cc.components())

print("✓ Connected Components passed")


# --------------------------------------------------
# Cycle Detection
# --------------------------------------------------

banner("Cycle Detection")

cycle = algokit.Graph.undirected(3)

cycle.add_edge(0, 1)
cycle.add_edge(1, 2)
cycle.add_edge(2, 0)

assert cycle.has_cycle()

print("✓ Undirected Cycle Detection passed")


# --------------------------------------------------
# Directed Cycle Detection
# --------------------------------------------------

banner("Directed Cycle Detection")

dg = algokit.Graph.directed(3)

dg.add_edge(0, 1)
dg.add_edge(1, 2)
dg.add_edge(2, 0)

assert dg.has_directed_cycle()

print("✓ Directed Cycle Detection passed")


# --------------------------------------------------
# Topological Sort
# --------------------------------------------------

banner("Topological Sort")

dag = algokit.Graph.directed(6)

dag.add_edge(5, 2)
dag.add_edge(5, 0)
dag.add_edge(4, 0)
dag.add_edge(4, 1)
dag.add_edge(2, 3)
dag.add_edge(3, 1)

topo = dag.topological_sort()

print("DFS Topological Order:", topo.order())

print("✓ DFS Topological Sort passed")


# --------------------------------------------------
# Kahn Topological Sort
# --------------------------------------------------

banner("Kahn Topological Sort")

kahn = dag.kahn_topological_sort()

print("Kahn Order:", kahn.order())

print("✓ Kahn Topological Sort passed")


# --------------------------------------------------
# Unweighted Shortest Path
# --------------------------------------------------

banner("Unweighted Shortest Path")

g2 = algokit.Graph.undirected(6)

g2.add_edge(0, 1)
g2.add_edge(1, 2)
g2.add_edge(2, 5)

sp = g2.shortest_path(0)

assert sp.distance(5) == 3

print("Distance:", sp.distance(5))
print("Path:", sp.path_to(5))

print("✓ Shortest Path passed")


# --------------------------------------------------
# Dijkstra
# --------------------------------------------------

banner("Dijkstra")

wg = algokit.Graph.directed(5)

wg.add_edge(0, 1, 4)
wg.add_edge(0, 2, 1)
wg.add_edge(2, 1, 2)
wg.add_edge(1, 3, 1)
wg.add_edge(2, 3, 5)
wg.add_edge(3, 4, 3)

dijkstra = wg.dijkstra(0)

assert dijkstra.distance(4) == 7

print("Distance:", dijkstra.distance(4))
print("Path:", dijkstra.path_to(4))

print("✓ Dijkstra passed")

# --------------------------------------------------
# Bellman-Ford
# --------------------------------------------------

banner("Bellman-Ford")

g = algokit.Graph.directed(5)

g.add_edge(0, 1, 6)
g.add_edge(0, 2, 7)
g.add_edge(1, 2, 8)
g.add_edge(1, 3, 5)
g.add_edge(1, 4, -4)
g.add_edge(2, 3, -3)
g.add_edge(2, 4, 9)
g.add_edge(3, 1, -2)
g.add_edge(4, 3, 7)

result = g.bellman_ford(0)

assert result.distance(0) == 0
assert result.distance(1) == 2
assert result.distance(2) == 7
assert result.distance(3) == 4
assert result.distance(4) == -2

print("Distance to 4:", result.distance(4))
print("Path to 4:", result.path_to(4))

print("✓ Bellman-Ford passed")

# --------------------------------------------------
# Bellman-Ford Negative Cycle
# --------------------------------------------------

banner("Bellman-Ford Negative Cycle")

g = algokit.Graph.directed(4)

g.add_edge(0, 1, 1)
g.add_edge(1, 2, -1)
g.add_edge(2, 1, -1)
g.add_edge(2, 3, 2)

try:
    g.bellman_ford(0)
    raise AssertionError(
        "Expected negative cycle exception."
    )

except RuntimeError as e:
    print(e)
    print("✓ Negative cycle detected")





# --------------------------------------------------
# Floyd-Warshall
# --------------------------------------------------

banner("Floyd-Warshall")

g = algokit.Graph.directed(5)

g.add_edge(0, 1, 4)
g.add_edge(0, 2, 1)
g.add_edge(2, 1, 2)
g.add_edge(1, 3, 1)
g.add_edge(2, 3, 5)
g.add_edge(3, 4, 3)

fw = g.floyd_warshall()

assert fw.distance(0, 4) == 7
assert fw.distance(0, 3) == 4
assert fw.distance(0, 2) == 1

assert fw.path(0, 4) == [0, 2, 1, 3, 4]

print("Distance 0 -> 4 :", fw.distance(0, 4))
print("Path 0 -> 4     :", fw.path(0, 4))

print("✓ Floyd-Warshall passed")

# --------------------------------------------------
# Floyd-Warshall Negative Cycle
# --------------------------------------------------

banner("Floyd-Warshall Negative Cycle")

g = algokit.Graph.directed(3)

g.add_edge(0, 1, 1)
g.add_edge(1, 2, -2)
g.add_edge(2, 0, -2)

try:
    g.floyd_warshall()

    raise AssertionError(
        "Expected negative cycle exception."
    )

except RuntimeError as e:

    print(e)

    print("✓ Negative cycle detected")

# --------------------------------------------------
# Disjoint Set Union
# --------------------------------------------------

banner("Disjoint Set Union")

dsu = algokit.DisjointSet(6)

assert dsu.component_count() == 6

assert dsu.unite(0, 1)
assert dsu.unite(1, 2)

assert dsu.connected(0, 2)
assert not dsu.connected(0, 3)

assert dsu.component_size(0) == 3
assert dsu.component_count() == 4

print("Root of 2:", dsu.find(2))
print("Component Size:", dsu.component_size(0))
print("Component Count:", dsu.component_count())

print("✓ Disjoint Set Union passed")

# --------------------------------------------------
# Kruskal
# --------------------------------------------------

banner("Kruskal")

g = algokit.Graph.undirected(4)

g.add_edge(0, 1, 1)
g.add_edge(0, 2, 4)
g.add_edge(1, 2, 2)
g.add_edge(1, 3, 5)
g.add_edge(2, 3, 3)

mst = g.kruskal()

assert mst.total_weight() == 6
assert mst.edge_count() == 3

print("Total Weight:", mst.total_weight())

print("Edges:")

for edge in mst.edges():
    print(
        edge.from_vertex,
        "->",
        edge.to_vertex,
        "(weight =", edge.weight, ")"
    )

print("✓ Kruskal passed")
# --------------------------------------------------

banner("Prim")

g = algokit.Graph.undirected(4)

g.add_edge(0,1,1)
g.add_edge(0,2,4)
g.add_edge(1,2,2)
g.add_edge(1,3,5)
g.add_edge(2,3,3)

mst = g.prim()

assert mst.total_weight() == 6
assert mst.edge_count() == 3

print("Total Weight:", mst.total_weight())

for edge in mst.edges():
    print(
        edge.from_vertex,
        "->",
        edge.to_vertex,
        "(weight =", edge.weight, ")"
    )

print("✓ Prim passed")

# --------------------------------------------------
# Strongly Connected Components
# --------------------------------------------------

banner("Strongly Connected Components")

g = algokit.Graph.directed(8)

g.add_edge(0, 1)
g.add_edge(1, 2)
g.add_edge(2, 0)

g.add_edge(2, 3)

g.add_edge(3, 4)
g.add_edge(4, 5)
g.add_edge(5, 3)

g.add_edge(6, 7)
g.add_edge(7, 6)

scc = g.strongly_connected_components()

assert scc.component_count() == 3

print("Component Count:", scc.component_count())

print("\nComponent IDs")

for vertex in range(8):
    print(
        f"{vertex} -> {scc.component_id(vertex)}"
    )

print("\nComponents")

for component in scc.components():
    print(component)

print("✓ Strongly Connected Components passed")

# ==================================================
# Bulk Graph Construction
# ==================================================

banner("Bulk Graph Construction")

# -----------------------------------------
# Unweighted Directed Graph
# -----------------------------------------

g = algokit.Graph.directed(5)

g.add_edges([
    (0, 1),
    (1, 2),
    (2, 3),
    (3, 4)
])

assert g.edge_count() == 4

print("BFS:", g.bfs(0).order())
print("DFS:", g.dfs(0).order())

sp = g.shortest_path(0)

assert sp.distance(4) == 4
assert sp.path_to(4) == [0, 1, 2, 3, 4]

print("Shortest Path:", sp.path_to(4))

print("✓ Unweighted bulk graph passed")


# -----------------------------------------
# Weighted Directed Graph
# -----------------------------------------

g = algokit.Graph.directed(5)

g.add_edges([
    (0, 1, 4.0),
    (0, 2, 1.0),
    (2, 1, 2.0),
    (1, 3, 1.0),
    (2, 3, 5.0),
    (3, 4, 3.0)
])

assert g.edge_count() == 6

dj = g.dijkstra(0)

print("Dijkstra distance:", dj.distance(4))
print("Dijkstra path:", dj.path_to(4))

assert dj.distance(4) == 7.0
assert dj.path_to(4) == [0, 2, 1, 3, 4]

bf = g.bellman_ford(0)

assert bf.distance(4) == 7.0
assert bf.path_to(4) == [0, 2, 1, 3, 4]

print("✓ Weighted bulk graph passed")


# -----------------------------------------
# Undirected Graph
# -----------------------------------------

g = algokit.Graph.undirected(4)

g.add_edges([
    (0, 1),
    (1, 2),
    (2, 3)
])

assert g.has_cycle() is False

cc = g.connected_components()

assert cc.component_count() == 1

print("Connected Components:", cc.components())

print("✓ Undirected bulk graph passed")


# -----------------------------------------
# Minimum Spanning Tree
# -----------------------------------------

g = algokit.Graph.undirected(4)

g.add_edges([
    (0, 1, 1),
    (0, 2, 4),
    (1, 2, 2),
    (1, 3, 5),
    (2, 3, 3)
])

kr = g.kruskal()
pr = g.prim()

print("Kruskal:", kr.total_weight())
print("Prim:", pr.total_weight())

assert kr.total_weight() == 6
assert pr.total_weight() == 6

print("✓ MST bulk graph passed")


print("\n🎉 Bulk Graph Construction tests passed!\n")

banner("Adjacency Matrix")

g = algokit.Graph.directed(4)

matrix = [

    [0,1,0,0],

    [0,0,2,0],

    [0,0,0,3],

    [0,0,0,0]

]

g.add_adjacency_matrix(matrix)

assert g.edge_count() == 3

result = g.dijkstra(0)

assert result.distance(3) == 6

assert result.path_to(3) == [0,1,2,3]

print("✓ Python list adjacency matrix passed")

# ==================================================
# Graph Inspection API
# ==================================================

banner("Graph Inspection API")

g = algokit.Graph.directed(3)

g.add_edge(0, 1, 5.0)
g.add_edge(0, 2, 7.0)

# -----------------------------------------
# edges()
# -----------------------------------------

edges = g.edges()

assert len(edges) == 2

assert edges[0].from_vertex == 0
assert edges[0].to_vertex == 1
assert edges[0].weight == 5.0

assert edges[1].from_vertex == 0
assert edges[1].to_vertex == 2
assert edges[1].weight == 7.0

print("Edges:")

for edge in edges:
    print(
        edge.from_vertex,
        "->",
        edge.to_vertex,
        "(weight =",
        edge.weight,
        ")"
    )

# -----------------------------------------
# neighbors()
# -----------------------------------------

neighbors = g.neighbors(0)

assert len(neighbors) == 2

assert neighbors[0].to_vertex == 1
assert neighbors[0].weight == 5.0

assert neighbors[1].to_vertex == 2
assert neighbors[1].weight == 7.0

print("\nNeighbors of vertex 0:")

for edge in neighbors:
    print(
        "0 ->",
        edge.to_vertex,
        "(weight =",
        edge.weight,
        ")"
    )

# -----------------------------------------
# transpose()
# -----------------------------------------

transpose = g.transpose()

transpose_edges = transpose.edges()

assert len(transpose_edges) == 2

assert transpose_edges[0].from_vertex == 1
assert transpose_edges[0].to_vertex == 0

assert transpose_edges[1].from_vertex == 2
assert transpose_edges[1].to_vertex == 0

print("\nTranspose Edges:")

for edge in transpose_edges:
    print(
        edge.from_vertex,
        "->",
        edge.to_vertex,
        "(weight =",
        edge.weight,
        ")"
    )

print("✓ Graph inspection API passed")

banner("SUCCESS")



print("🎉 ALL PYTHON TESTS PASSED!")
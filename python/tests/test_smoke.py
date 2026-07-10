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

banner("SUCCESS")

print("🎉 ALL PYTHON TESTS PASSED!")
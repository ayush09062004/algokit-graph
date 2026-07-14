# AlgoKit Graph

<p align="center">

AlgoKit Graph is currently a high-performance graph algorithms library written in modern C++ with Python bindings powered by pybind11. It combines native C++ execution speed with a clean, Pythonic interface, making it suitable for education, research, and performance-sensitive graph analytics. I envision AlgoKit-Graph as a "The high-performance STL for Graph Computing in Python".

- Documentation: https://ayush09062004.github.io/algokit-graph-documentation/
- Test Notebooks(.ipynb): https://github.com/ayush09062004/algokit-graph-documentation

[![C++17](https://img.shields.io/badge/C%2B%2B-17-blue.svg)]()
[![Python](https://img.shields.io/badge/Python-3.10%2B-yellow.svg)]()
[![License](https://img.shields.io/badge/License-MIT-green.svg)]()

</p>

---

## Installation

Install the latest development version directly from GitHub:

```bash
pip install git+https://github.com/ayush09062004/algokit-graph.git
```

Or, in Google Colab:

```python
!pip install git+https://github.com/ayush09062004/algokit-graph.git
```
---

## Features

### Graph Types

- Directed Graphs
- Undirected Graphs
- Weighted Graphs
- Unweighted Graphs

---

## Implemented Algorithms

| Category | Algorithm | C++ | Python | Tested |
|----------|-----------|:---:|:------:|:------:|
| Traversal | Breadth First Search (BFS) | Y | Y | Y |
| Traversal | Depth First Search (DFS) | Y | Y | Y |
| Connectivity | Connected Components | Y | Y | Y |
| Connectivity | Strongly Connected Components (Kosaraju) | Y | Y | Y |
| Cycle Detection | Undirected Cycle Detection | Y | Y | Y |
| Cycle Detection | Directed Cycle Detection | Y | Y | Y |
| DAG | Topological Sort (DFS) | Y | Y | Y |
| DAG | Kahn's Topological Sort | Y | Y | Y |
| Shortest Paths | BFS Shortest Path | Y | Y | Y |
| Shortest Paths | Dijkstra | Y | Y | Y |
| Shortest Paths | Bellman-Ford | Y | Y | Y |
| Shortest Paths | Floyd-Warshall | Y | Y | Y |
| Minimum Spanning Tree | Kruskal | Y | Y | Y |
| Minimum Spanning Tree | Prim | Y | Y | Y |
| Data Structures | Disjoint Set Union (Union-Find) | Y | Y | Y |

---

# Library Architecture

```
Graph
 │
 ├── Traversal
 │      ├── BFS
 │      └── DFS
 │
 ├── Connectivity
 │      ├── Connected Components
 │      └── Strongly Connected Components
 │
 ├── Cycle Detection
 │      ├── Undirected
 │      └── Directed
 │
 ├── DAG Algorithms
 │      ├── Topological Sort
 │      └── Kahn
 │
 ├── Shortest Paths
 │      ├── BFS
 │      ├── Dijkstra
 │      ├── Bellman-Ford
 │      └── Floyd-Warshall
 │
 └── Minimum Spanning Trees
        ├── Kruskal
        └── Prim

DisjointSet
```

# Project Structure

```
algokit-graph/

├── app/
│
├── bindings/
│
├── cpp/
│   ├── include/
│   └── src/
│
├── python/
│
├── tests/
│
├── docs/
│
├── CMakeLists.txt
│
└── README.md
```

---

# Complexity Summary

| Algorithm | Time Complexity |
|------------|----------------|
| BFS | O(V + E) |
| DFS | O(V + E) |
| Connected Components | O(V + E) |
| Strongly Connected Components | O(V + E) |
| Cycle Detection | O(V + E) |
| Topological Sort | O(V + E) |
| Kahn's Algorithm | O(V + E) |
| Shortest Path (BFS) | O(V + E) |
| Dijkstra | O(E log V) |
| Bellman-Ford | O(VE) |
| Floyd-Warshall | O(V³) |
| Kruskal | O(E log E) |
| Prim | O(E log V) |
| Disjoint Set Operations | O(α(N)) |

---

# Benchmarks

`algokit-graph` doesn't ship a benchmark script of its own, so the numbers
below come from an independent verification notebook that builds the
package from source exactly as the [Installation](#installation) section
above describes, then times each implemented algorithm against a pure-Python
implementation of the *same* algorithm on an identical random graph (built
once, fed to both sides, so neither gets an easier input). Every benchmark
asserts correctness before recording a timing. Measured on a Google Colab
CPU runtime; absolute times will vary with the machine, but the relative
ratios should be stable.

### V = 10,000 vertices, E = 50,000 edges

| Category | Algorithm | Python | `algokit_graph` | Speedup | Compared against |
|---|---|---:|---:|---:|---|
| Traversal | BFS | 0.00975s | 0.00062s | **15.70×** | `collections.deque` BFS |
| Traversal | DFS | 0.03594s | 0.00166s | **21.58×** | iterative stack-based DFS |
| Connectivity | Connected Components | 0.03221s | 0.00204s | **15.77×** | iterative DFS component count |
| Shortest paths | Dijkstra | 0.04650s | 0.00313s | **14.85×** | `heapq`-based Dijkstra |
| Shortest paths | Bellman-Ford | 0.01103s | 0.00018s | **59.97×** | O(V·E) Python Bellman-Ford (scaled-down n) |
| MST | Kruskal | 0.07170s | 0.00432s | **16.59×** | `sorted()` + union-find in Python |
| DAG | Kahn's Topological Sort | 0.00820s | 0.00064s | **12.83×** | `collections.deque` Kahn's algorithm |

### Larger scale — V = 100,000 vertices, E = 500,000 edges

Re-run at 10× the graph size to check whether the speedups hold up as the
input grows, rather than being an artifact of a small graph fitting in cache.

| Category | Algorithm | Python | `algokit_graph` | Speedup | Compared against |
|---|---|---:|---:|---:|---|
| Traversal | BFS | 0.19013s | 0.01210s | **15.71×** | `collections.deque` BFS |
| Traversal | DFS | 0.22067s | 0.02568s | **8.59×** | iterative stack-based DFS |
| Connectivity | Connected Components | 0.30073s | 0.04321s | **6.96×** | iterative DFS component count |
| Shortest paths | Dijkstra | 0.54582s | 0.04703s | **11.61×** | `heapq`-based Dijkstra |
| Shortest paths | Bellman-Ford | 0.10003s | 0.00143s | **70.10×** | O(V·E) Python Bellman-Ford (scaled-down n) |
| MST | Kruskal | 0.45049s | 0.03646s | **12.35×** | `sorted()` + union-find in Python |
| DAG | Kahn's Topological Sort | 0.16868s | 0.01355s | **12.45×** | `collections.deque` Kahn's algorithm |

Ratios stay in the same **~7×–70×** band at 10× the graph size — BFS and
Bellman-Ford hold essentially steady or improve, while DFS/Connected
Components/Kruskal narrow somewhat but remain solidly in native-speedup
territory.

**Why graph algorithms hold up well:** every one of these calls
(`g.bfs(0)`, `g.dijkstra(0)`, ...) crosses the Python↔C++ boundary
**once** — the entire traversal or shortest-path computation runs natively
inside the pybind11-wrapped C++ layer, and only the final result (order
list, distance array, MST edge list) comes back to Python. That's a very
different access pattern from calling many small per-element operations
from Python one at a time, which is why the speedups here are consistent
rather than mixed.

---

# Testing

AlgoKit includes comprehensive unit tests for every implemented algorithm.

```bash
cmake -B build

cmake --build build

ctest --test-dir build --output-on-failure
```

---

# Roadmap

## Completed

- Graph Data Structure
- Python Bindings
- BFS
- DFS
- Connected Components
- Strongly Connected Components
- Cycle Detection
- Topological Sort
- Kahn's Algorithm
- BFS Shortest Path
- Dijkstra
- Bellman-Ford
- Floyd-Warshall
- Disjoint Set Union
- Kruskal
- Prim

## In Progress

- Bridges (Tarjan)

- Articulation Points (Tarjan)
  
- V2.0.0 **The STL for Graph Computing in Python**: A framework of high-performance graph primitives that lets users build their own algorithms while everything computationally intensive remains in C++.

## Future

- V2.0.0 **The STL for Graph Computing in Python**
- Maximum Flow
- Edmonds-Karp
- Dinic
- Johnson's Algorithm
- A* Search
- Euler Tour
- Lowest Common Ancestor
- Binary Lifting
- Hopcroft-Karp
- Hungarian Algorithm

---

# Contributing

Contributions, bug reports, feature requests, and documentation improvements are welcome.

Please open an issue or submit a pull request.

---

# License

MIT License


---

# Quick C++ Example

```cpp
#include <iostream>
#include "algokit/graph.hpp"

using namespace algokit;

int main()
{
    Graph graph = Graph::directed(5);

    graph.add_edge(0, 1);
    graph.add_edge(1, 2);
    graph.add_edge(2, 3);
    graph.add_edge(3, 4);

    auto bfs = graph.bfs(0);

    for (auto v : bfs.order())
        std::cout << v << " ";

    return 0;
}
```

---

# Quick Python Example

```python
import algokit

graph = algokit.Graph.directed(5)

graph.add_edge(0, 1)
graph.add_edge(1, 2)
graph.add_edge(2, 3)
graph.add_edge(3, 4)

bfs = graph.bfs(0)

print(bfs.order())
```

---

# Shortest Path Example

```cpp
Graph graph = Graph::directed(5);

graph.add_edge(0,1,2);
graph.add_edge(1,2,5);
graph.add_edge(0,3,1);
graph.add_edge(3,4,2);
graph.add_edge(4,2,1);

auto result = graph.dijkstra(0);

std::cout << result.distance(2);
```

---

# Minimum Spanning Tree Example

```cpp
Graph graph = Graph::undirected(4);

graph.add_edge(0,1,1);
graph.add_edge(1,2,2);
graph.add_edge(2,3,3);
graph.add_edge(0,3,5);

auto mst = graph.kruskal();

std::cout << mst.total_weight();
```

---

# Python Bindings

Every implemented algorithm is available directly from Python.

```python
graph.bfs()

graph.dfs()

graph.connected_components()

graph.strongly_connected_components()

graph.has_cycle()

graph.has_directed_cycle()

graph.topological_sort()

graph.kahn_topological_sort()

graph.shortest_path()

graph.dijkstra()

graph.bellman_ford()

graph.floyd_warshall()

graph.kruskal()

graph.prim()
```

Data structures

```python
dsu = algokit.DisjointSet(10)

dsu.unite(0,1)

dsu.connected(0,1)

dsu.component_size(0)

dsu.component_count()
```

---

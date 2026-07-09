# AlgoKit Graph

> A modern, high-performance C++ graph algorithms library with planned Python bindings.

AlgoKit Graph aims to provide clean, reusable, and well-tested implementations of fundamental graph algorithms while maintaining an intuitive API for developers, students, researchers, and competitive programmers.

---

# Features

## Graph

- ✅ Directed Graph
- ✅ Undirected Graph
- ✅ Weighted Edges

## Traversal

- ✅ Breadth First Search (BFS)
- ✅ Depth First Search (DFS)

## Connectivity

- ✅ Connected Components

---

# Example

```cpp
#include <iostream>

#include "algokit/graph.hpp"

using namespace algokit;

int main()
{
    Graph graph = Graph::undirected(6);

    graph.add_edge(0,1);
    graph.add_edge(1,2);
    graph.add_edge(3,4);

    auto result = graph.connected_components();

    std::cout
        << "Connected Components : "
        << result.component_count()
        << '\n';
}
```

Output

```text
Connected Components : 3
```

---

# Build

```bash
cmake -B build
cmake --build build
```

---

# Run Demo

```bash
./build/graph_demo
```

---

# Run Tests

```bash
ctest --test-dir build --output-on-failure
```

---

# Project Structure

```
algokit-graph/

├── app/
├── bindings/
├── cpp/
│   ├── include/
│   └── src/
├── tests/
├── examples/
└── docs/
```

---

# Implemented Algorithms

| Category | Algorithm | Status |
|-----------|-----------|--------|
| Graph | Graph Class | ✅ |
| Traversal | Breadth First Search | ✅ |
| Traversal | Depth First Search | ✅ |
| Connectivity | Connected Components | ✅ |

---

# Roadmap

## Graph Traversal

- ✅ BFS
- ✅ DFS

## Graph Connectivity

- ✅ Connected Components
- ⏳ Cycle Detection (Undirected)
- ⏳ Cycle Detection (Directed)

## DAG Algorithms

- ⏳ Topological Sort (DFS)
- ⏳ Kahn's Algorithm

## Shortest Paths

- ⏳ Dijkstra
- ⏳ Bellman-Ford
- ⏳ Floyd-Warshall

## Minimum Spanning Tree

- ⏳ Disjoint Set Union (DSU)
- ⏳ Kruskal
- ⏳ Prim

## Advanced Algorithms

- ⏳ Strongly Connected Components
- ⏳ Bridges
- ⏳ Articulation Points
- ⏳ Euler Tour

---

# Testing

Every algorithm in AlgoKit includes dedicated unit tests.

Current test coverage includes:

- ✅ Graph
- ✅ BFS
- ✅ DFS
- ✅ Connected Components

---

# Version

Current Version

```
v0.1.0
```

---

# License

MIT License

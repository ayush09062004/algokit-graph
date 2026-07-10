# Architecture

AlgoKit follows a layered architecture.

```
Applications

↓

Python Bindings

↓

Algorithms

↓

Result Classes

↓

Graph
```

---

## Core

- Graph
- Disjoint Set Union

---

## Algorithms

Every algorithm is implemented independently.

Examples

- bfs.cpp
- dfs.cpp
- dijkstra.cpp
- prim.cpp

Algorithms never contain graph storage.

They operate on the Graph interface.

---

## Result Classes

Every algorithm returns its own immutable result type.

Examples

- BFSResult
- DFSResult
- ConnectedComponentsResult
- ShortestPathResult
- FloydWarshallResult
- MSTResult

This keeps the API type-safe and extensible.

---

## Python

Every C++ API is exposed through pybind11.

The Python API closely mirrors the C++ API.
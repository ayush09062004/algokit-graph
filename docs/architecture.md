# Architecture

AlgoKit separates algorithms from the graph data structure.

```
Graph
│
├── BFS
│
├── DFS
│     │
│     └── DFS Engine
│
└── Connected Components
```

Every algorithm is implemented as

- header
- source
- result class
- unit tests

This keeps the library modular and easy to extend.
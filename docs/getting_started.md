# Getting Started

## Requirements

- C++17
- CMake 3.20+

---

## Clone

```bash
git clone https://github.com/<username>/algokit-graph.git
```

---

## Build

```bash
cmake -B build

cmake --build build
```

---

## Run Demo

```bash
./build/graph_demo
```

---

## Run Tests

```bash
ctest --test-dir build --output-on-failure
```
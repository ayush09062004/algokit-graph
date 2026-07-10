# Getting Started

## Requirements

- C++17
- CMake 3.20+
- Python 3.10+ (optional)

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

---

## Python Bindings

Configure

```bash
cmake -B build \
-Dpybind11_DIR=$(python3 -c "import pybind11; print(pybind11.get_cmake_dir())")
```

Build

```bash
cmake --build build
```

Run

```bash
python3
```

```python
import sys

sys.path.append("build")

import algokit
```
# Disjoint Set Union

Disjoint Set Union (Union-Find) maintains disjoint sets with efficient merge and lookup operations.

AlgoKit uses:

- Path Compression
- Union by Size

---

## Complexity

```
Nearly O(1)
```

(amortized)

---

## C++

```cpp
DisjointSet dsu(10);

dsu.unite(0,1);

dsu.connected(0,1);
```

---

## Python

```python
dsu = algokit.DisjointSet(10)
```
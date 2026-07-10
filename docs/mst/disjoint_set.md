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

dsu.find(3);               // std::size_t, root of 3's set; throws std::out_of_range if invalid
dsu.unite(0, 1);            // bool, false if 0 and 1 were already in the same set
dsu.connected(0, 1);        // bool
dsu.component_size(0);      // std::size_t, size of the set containing 0
dsu.component_count() const; // std::size_t, number of disjoint sets remaining
```

`DisjointSet(size)` creates `size` singleton sets, numbered `0..size-1`.
`component_count()` starts at `size` and decreases by one on every
successful `unite()`.

---

## Python

```python
dsu = algokit.DisjointSet(10)

dsu.find(3)
dsu.unite(0, 1)
dsu.connected(0, 1)
dsu.component_size(0)
dsu.component_count()
```
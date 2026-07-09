# Breadth First Search

Breadth First Search explores vertices level by level.

## Complexity

Time: O(V + E)

Space: O(V)

## Example

```cpp
auto result = graph.bfs(0);

for (auto vertex : result.order())
{
    std::cout << vertex << ' ';
}
```
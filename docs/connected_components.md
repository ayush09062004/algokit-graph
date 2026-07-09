# Connected Components

Connected Components partition an undirected graph into maximal connected subgraphs.

## Example

```cpp
auto result = graph.connected_components();

std::cout << result.component_count();
```

## Complexity

Time: O(V + E)

Space: O(V)

## Notes

Connected Components are only defined for undirected graphs.

Calling this function on a directed graph throws a `std::logic_error`.
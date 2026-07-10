#include "algokit/strongly_connected_components.hpp"

#include "algokit/graph.hpp"

#include <algorithm>
#include <stdexcept>
#include <vector>

namespace algokit
{

namespace
{

void dfs_finish_order(
    const Graph& graph,
    std::size_t vertex,
    std::vector<bool>& visited,
    std::vector<std::size_t>& order)
{
    visited[vertex] = true;

    for (const auto& edge : graph.neighbors(vertex))
    {
        if (!visited[edge.to])
        {
            dfs_finish_order(
                graph,
                edge.to,
                visited,
                order
            );
        }
    }

    order.push_back(vertex);
}

void dfs_collect(
    const Graph& graph,
    std::size_t vertex,
    std::vector<bool>& visited,
    std::vector<int>& component_id,
    int current_component,
    std::vector<std::size_t>& component)
{
    visited[vertex] = true;

    component_id[vertex] = current_component;

    component.push_back(vertex);

    for (const auto& edge : graph.neighbors(vertex))
    {
        if (!visited[edge.to])
        {
            dfs_collect(
                graph,
                edge.to,
                visited,
                component_id,
                current_component,
                component
            );
        }
    }
}

} // namespace

StronglyConnectedComponentsResult
strongly_connected_components(
    const Graph& graph)
{
    if (!graph.is_directed())
    {
        throw std::logic_error(
            "Strongly connected components are only supported for directed graphs."
        );
    }

    const std::size_t vertices =
        graph.vertex_count();

    std::vector<bool> visited(
        vertices,
        false
    );

    std::vector<std::size_t> order;

    //--------------------------------------------------
    // First DFS
    //--------------------------------------------------

    for (std::size_t i = 0;
         i < vertices;
         ++i)
    {
        if (!visited[i])
        {
            dfs_finish_order(
                graph,
                i,
                visited,
                order
            );
        }
    }

    //--------------------------------------------------
    // Transpose
    //--------------------------------------------------

    Graph transpose =
        graph.transpose();

    std::fill(
        visited.begin(),
        visited.end(),
        false
    );

    std::reverse(
        order.begin(),
        order.end()
    );

    std::vector<int> component_id(
        vertices,
        -1
    );

    std::vector<
        std::vector<std::size_t>
    > components;

    int current_component = 0;

    //--------------------------------------------------
    // Second DFS
    //--------------------------------------------------

    for (std::size_t vertex : order)
    {
        if (visited[vertex])
        {
            continue;
        }

        components.emplace_back();

        dfs_collect(
            transpose,
            vertex,
            visited,
            component_id,
            current_component,
            components.back()
        );

        ++current_component;
    }

    return StronglyConnectedComponentsResult(
        std::move(component_id),
        std::move(components)
    );
}

} // namespace algokit
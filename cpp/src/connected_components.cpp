#include "algokit/connected_components.hpp"

#include "algokit/internal/dfs_engine.hpp"

#include <utility>

namespace algokit {

ConnectedComponentsResult connected_components(
    const Graph& graph)
{
    internal::DFSState state(graph.vertex_count());

    std::vector<int> component_ids(
        graph.vertex_count(),
        -1
    );

    std::vector<std::vector<std::size_t>> components;

    int current_component = 0;

    for (std::size_t vertex = 0;
         vertex < graph.vertex_count();
         ++vertex)
    {
        if (state.visited[vertex])
        {
            continue;
        }

        std::size_t previous_size =
            state.order.size();

        internal::dfs_visit(
            graph,
            vertex,
            state
        );

        components.emplace_back();

        for (std::size_t i = previous_size;
             i < state.order.size();
             ++i)
        {
            std::size_t node =
                state.order[i];

            component_ids[node] =
                current_component;

            components.back().push_back(node);
        }

        ++current_component;
    }

    return ConnectedComponentsResult(
        std::move(component_ids),
        std::move(components)
    );
}

} // namespace algokit
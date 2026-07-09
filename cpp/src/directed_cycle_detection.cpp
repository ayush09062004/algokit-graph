#include "algokit/directed_cycle_detection.hpp"
#include "algokit/graph.hpp"

#include <vector>

namespace algokit {

namespace {

enum class Color
{
    White,
    Gray,
    Black
};

bool dfs_has_cycle(
    const Graph& graph,
    std::size_t current,
    std::vector<Color>& color)
{
    color[current] = Color::Gray;

    for (const Edge& edge : graph.neighbors(current))
    {
        std::size_t neighbor = edge.to;

        if (color[neighbor] == Color::Gray)
        {
            return true;
        }

        if (color[neighbor] == Color::White)
        {
            if (dfs_has_cycle(
                    graph,
                    neighbor,
                    color))
            {
                return true;
            }
        }
    }

    color[current] = Color::Black;

    return false;
}

} // anonymous namespace

bool has_directed_cycle(
    const Graph& graph)
{
    std::vector<Color> color(
        graph.vertex_count(),
        Color::White
    );

    for (std::size_t vertex = 0;
         vertex < graph.vertex_count();
         ++vertex)
    {
        if (color[vertex] != Color::White)
        {
            continue;
        }

        if (dfs_has_cycle(
                graph,
                vertex,
                color))
        {
            return true;
        }
    }

    return false;
}

} // namespace algokit
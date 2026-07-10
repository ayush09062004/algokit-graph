#include "algokit/floyd_warshall.hpp"
#include "algokit/graph.hpp"
#include "algokit/types.hpp"
#include <stdexcept>
#include <utility>
#include <vector>

namespace algokit {

FloydWarshallResult
floyd_warshall(
    const Graph& graph)
{
    const std::size_t vertices =
        graph.vertex_count();

    std::vector<std::vector<Weight>>
        distance(
            vertices,
            std::vector<Weight>(
                vertices,
                INF
            )
        );

    std::vector<std::vector<int>>
        next(
            vertices,
            std::vector<int>(
                vertices,
                -1
            )
        );

    //--------------------------------------------------
    // Initialize
    //--------------------------------------------------

    for (std::size_t i = 0;
         i < vertices;
         ++i)
    {
        distance[i][i] = 0.0;

        next[i][i] =
            static_cast<int>(i);
    }

    for (const GraphEdge& edge : graph.edges())
{
    if (edge.weight < distance[edge.from][edge.to])
    {
        distance[edge.from][edge.to] = edge.weight;

        next[edge.from][edge.to] =
            static_cast<int>(edge.to);
    }

    if (!graph.is_directed())
    {
        if (edge.weight < distance[edge.to][edge.from])
        {
            distance[edge.to][edge.from] =
                edge.weight;

            next[edge.to][edge.from] =
                static_cast<int>(edge.from);
        }
    }
}

    //--------------------------------------------------
    // Floyd-Warshall
    //--------------------------------------------------

    for (std::size_t k = 0;
         k < vertices;
         ++k)
    {
        for (std::size_t i = 0;
             i < vertices;
             ++i)
        {
            if (distance[i][k] == INF)
            {
                continue;
            }

            for (std::size_t j = 0;
                 j < vertices;
                 ++j)
            {
                if (distance[k][j] == INF)
                {
                    continue;
                }

                Weight candidate =
                    distance[i][k] +
                    distance[k][j];

                if (candidate >=
                    distance[i][j])
                {
                    continue;
                }

                distance[i][j] =
                    candidate;

                next[i][j] =
                    next[i][k];
            }
        }
    }

    //--------------------------------------------------
    // Detect negative cycles
    //--------------------------------------------------

    for (std::size_t i = 0;
         i < vertices;
         ++i)
    {
        if (distance[i][i] < 0)
        {
            throw std::logic_error(
                "Floyd-Warshall detected a negative-weight cycle."
            );
        }
    }

    return FloydWarshallResult(
        std::move(distance),
        std::move(next)
    );
}

} // namespace algokit
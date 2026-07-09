#pragma once

#include <cstddef>
#include <vector>

namespace algokit {

class TopologicalSortResult
{
public:

    explicit TopologicalSortResult(
        std::vector<std::size_t> order
    );

    const std::vector<std::size_t>& order() const;

private:

    std::vector<std::size_t> order_;
};

} // namespace algokit
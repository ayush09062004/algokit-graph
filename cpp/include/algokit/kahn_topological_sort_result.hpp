#pragma once

#include <cstddef>
#include <vector>

namespace algokit {

class KahnTopologicalSortResult
{
public:

    explicit KahnTopologicalSortResult(
        std::vector<std::size_t> order
    );

    const std::vector<std::size_t>& order() const;

private:

    std::vector<std::size_t> order_;
};

} // namespace algokit
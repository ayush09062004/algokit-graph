#pragma once

#include <cstddef>
#include <vector>

namespace algokit {

class BFSResult {
public:
    BFSResult(
        std::vector<std::size_t> order,
        std::vector<int> distance,
        std::vector<int> parent
    );

    const std::vector<std::size_t>& order() const;

    const std::vector<int>& distance() const;

    const std::vector<int>& parent() const;

private:
    std::vector<std::size_t> order_;

    std::vector<int> distance_;

    std::vector<int> parent_;
};

} // namespace algokit
#pragma once

#include <cstddef>
#include <vector>

namespace algokit {

class DFSResult {
public:
    DFSResult(
        std::vector<std::size_t> order,
        std::vector<int> parent,
        std::vector<int> discovery_time,
        std::vector<int> finish_time
    );

    const std::vector<std::size_t>& order() const;

    const std::vector<int>& parent() const;

    const std::vector<int>& discovery_time() const;

    const std::vector<int>& finish_time() const;

private:
    std::vector<std::size_t> order_;

    std::vector<int> parent_;

    std::vector<int> discovery_time_;

    std::vector<int> finish_time_;
};

} // namespace algokit
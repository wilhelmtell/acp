#ifndef ACP_TEST_PATHS_HH_
#define ACP_TEST_PATHS_HH_

#include <boost/iterator/transform_iterator.hpp>
#include "file.hh"
#include <vector>
#include <functional>

namespace acp { namespace test {
struct paths {
    typedef
        std::vector<file> container;
    typedef
        decltype(std::bind(&file::path, std::placeholders::_1))
        iterator_transform;
    typedef
        boost::transform_iterator<iterator_transform,container::const_iterator>
        const_iterator;

    explicit paths(int n);

    const_iterator begin() const;
    const_iterator end() const;

private:
    container files;
    iterator_transform transform;
};
} }  // namespace acp::test

#endif  // ACP_TEST_PATHS_HH_

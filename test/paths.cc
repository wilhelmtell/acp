#include "paths.hh"
#include "file.hh"
#include <boost/iterator/transform_iterator.hpp>
#include <functional>

namespace acp { namespace test {
paths::paths(int n)
: files(n)
, transform(std::bind(&file::path, std::placeholders::_1))
{
}

paths::const_iterator paths::begin() const
{
    return boost::make_transform_iterator(files.begin(), transform);
}

paths::const_iterator paths::end() const
{
    return boost::make_transform_iterator(files.end(), transform);
}
} }  // namespace acp::test

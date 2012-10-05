#ifndef ACP_TEST_DIRECTORY_HH_
#define ACP_TEST_DIRECTORY_HH_

#include <boost/filesystem/path.hpp>

namespace acp { namespace test {
struct directory {
    directory();
    explicit directory(boost::filesystem::path const& pathname);
    ~directory();
    directory(directory&&) = default;
    directory& operator=(directory&&) = default;
    directory(directory const&) = delete;
    directory& operator=(directory const&) = delete;

    boost::filesystem::path path() const;

private:
    boost::filesystem::path at;
    boost::filesystem::path relative_pathname;
};
} }  // namespace acp::test

#endif  // ACP_TEST_DIRECTORY_HH_

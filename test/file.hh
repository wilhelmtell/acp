#ifndef ACP_TEST_FILE_HH_
#define ACP_TEST_FILE_HH_

#include <boost/filesystem/path.hpp>

namespace acp { namespace test {
struct file {
    file();
    explicit file(boost::filesystem::path const& pathname);
    ~file();
    file(file&&) = default;
    file& operator=(file&&) = default;
    file(file const&) = delete;
    file& operator=(file const&) = delete;

    boost::filesystem::path path() const;
    boost::filesystem::path parent_path() const;

private:
    boost::filesystem::path at;
    boost::filesystem::path relative_pathname;
};

template<typename T>
file& operator<<(file& in, T const& value);
} }  // namespace acp::test

#include "file.tcc"

#endif  // ACP_TEST_FILE_HH_

#include "contents_of.hh"
#include "file.hh"
#include <algorithm>
#include <iterator>
#include <boost/filesystem/operations.hpp>
#include <fstream>

namespace fs = boost::filesystem;

namespace {
bool equal_size(fs::path const& lhs, fs::path const& rhs)
{
    return fs::file_size(lhs) == fs::file_size(rhs);
}

// the lhs file contents are the start of the rhs file contents
bool is_contents_prefix(fs::path const& lhs, fs::path const& rhs)
{
    std::ifstream lfile(lhs.string());
    std::ifstream rfile(rhs.string());
    std::istreambuf_iterator<char> const lfile_b(lfile), lfile_e;
    std::istreambuf_iterator<char> const rfile_b(rfile);
    return std::equal(lfile_b, lfile_e, rfile_b);
}
}  // namespace


namespace acp { namespace test {
contents_of::contents_of(fs::path const& p)
: path(p)
{
}

contents_of::contents_of(file const& f)
: path(f.path())
{
}

bool operator==(contents_of const& lhs, contents_of const& rhs)
{
    auto const lpath(lhs.path);
    auto const rpath(rhs.path);
    return equal_size(lpath, rpath) && is_contents_prefix(lpath, rpath);
}

bool operator!=(contents_of const& lhs, contents_of const& rhs)
{
    return ! (lhs == rhs);
}
} }  // namespace acp::test

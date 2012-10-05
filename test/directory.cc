#include "directory.hh"
#include <boost/filesystem/operations.hpp>
#include <cassert>

namespace fs = boost::filesystem;

namespace acp { namespace test {
directory::directory()
: directory(fs::unique_path())
{
}

directory::directory(fs::path const& pathname)
: at(fs::temp_directory_path() / fs::unique_path())
, relative_pathname(pathname)
{
    assert( ! fs::exists(at) );
    fs::create_directories(at / relative_pathname);
    assert( fs::is_directory(at / relative_pathname) );
}

directory::~directory()
{
    assert( fs::is_directory(at / relative_pathname) );
    boost::system::error_code e;
    fs::remove_all(at, e);
    assert( ! e );
}

fs::path directory::path() const
{
    return at / relative_pathname;
}
} }  // namespace acp::test

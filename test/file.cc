#include "file.hh"
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/system/error_code.hpp>
#include <fstream>
#include <cassert>

namespace fs = boost::filesystem;

namespace acp { namespace test {
file::file()
: file(fs::unique_path())
{
}

file::file(fs::path const& pathname)
: at(fs::temp_directory_path() / fs::unique_path())
, relative_pathname(pathname)
{
    assert( ! fs::exists(at) );
    fs::create_directories(at / relative_pathname.parent_path());
    std::ofstream out((at / relative_pathname).string());
    assert( fs::is_regular_file(at / relative_pathname) );
}

file::~file()
{
    assert( fs::is_regular_file(at / relative_pathname) );
    boost::system::error_code e;
    fs::remove_all(at, e);
    assert( ! e );
}

fs::path file::path() const
{
    return at / relative_pathname;
}

fs::path file::parent_path() const
{
    return at;
}
} }  // namespace acp::test

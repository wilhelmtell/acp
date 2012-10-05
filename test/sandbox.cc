#include "sandbox.hh"
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/system/error_code.hpp>
#include <fstream>
#include <cassert>

namespace fs = boost::filesystem;

namespace acp { namespace test {
sandbox::sandbox()
: directory(fs::temp_directory_path() / fs::unique_path())
{
    assert( ! fs::is_directory(directory) );
    fs::create_directories(directory);
    assert( fs::is_directory(directory) );
}

sandbox::~sandbox()
{
    boost::system::error_code e;
    fs::remove_all(directory, e);
}

fs::path sandbox::path() const
{
    assert( fs::is_directory(directory) );
    return directory;
}
} }  // namespace acp::test

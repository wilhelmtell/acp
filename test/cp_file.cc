#include <catch/catch.hpp>
#include "file.hh"
#include <acp/cp_file.hh>
#include <boost/filesystem/operations.hpp>

namespace fs = boost::filesystem;

TEST_CASE( "cp_file/copy a file", "" ) {
    acp::test::file const file("source");
    auto const target(file.parent_path() / "copy");
    acp::cp_file const op(file.path(), target); 
    REQUIRE( fs::is_regular_file(target) );
}

TEST_CASE( "cp_file/copy a file, then roll back", "" ) {
    acp::test::file const file("source");
    auto const target(file.parent_path() / "copy");
    { acp::cp_file const op(file.path(), target); }
    REQUIRE( ! fs::exists(target) );
}

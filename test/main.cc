#define CATCH_CONFIG_MAIN
#include <catch/catch.hpp>
#include "sandbox.hh"
#include <acp/cp_file.hh>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <fstream>

namespace fs = boost::filesystem;

TEST_CASE( "cp_file/copy a file", "" ) {
    acp::test::sandbox box;
    auto const source(box.path() / "file");
    std::ofstream(source.string());
    fs::path const target(source.string() + ".cp");
    acp::cp_file op(source, target);
    REQUIRE( fs::is_regular_file(target) );
} TEST_CASE( "cp_file/copy a file, then roll back", "" ) {
    acp::test::sandbox box;
    auto const source(box.path() / "file");
    std::ofstream(source.string());
    fs::path const target(source.string() + ".cp");
    { acp::cp_file op(source, target); }
    REQUIRE( ! fs::exists(target) );
}

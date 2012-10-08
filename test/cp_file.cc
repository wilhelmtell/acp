#include <catch/catch.hpp>
#include "file.hh"
#include "contents_of.hh"
#include <acp/cp_file.hh>
#include <boost/filesystem/operations.hpp>
#include <fstream>

namespace test = acp::test;
namespace fs = boost::filesystem;

TEST_CASE( "cp_file/file copy creates a file", "" ) {
    test::file const file("source");
    auto const target(file.parent_path() / "copy");
    {
        acp::cp_file(file.path(), target).commit();
    }
    REQUIRE( fs::is_regular_file(target) );
}

TEST_CASE( "cp_file/empty file copy duplicates file contents", "" ) {
    test::file const original("source");
    auto const target(original.parent_path() / "copy");
    {
        acp::cp_file(original.path(), target).commit();
    }
    REQUIRE( test::contents_of(original) == test::contents_of(target) );
}

TEST_CASE( "cp_file/file copy duplicates file contents", "" ) {
    test::file original("source");
    original << "some contents";
    auto const target(original.parent_path() / "copy");
    {
        acp::cp_file(original.path(), target).commit();
    }
    REQUIRE( test::contents_of(original) == test::contents_of(target) );
}

TEST_CASE( "cp_file/save file a as file b", "" ) {
    test::file const file("source");
    fs::path const target(file.path().string() + ".copy");
    {
        acp::cp_file(file.path(), target).commit();
    }
    REQUIRE( fs::is_regular_file(target) );
}

TEST_CASE( "cp_file/copy a file, then roll back", "" ) {
    test::file const file("source");
    auto const target(file.parent_path() / "copy");
    {
        acp::cp_file(file.path(), target);
    }
    REQUIRE( ! fs::exists(target) );
}

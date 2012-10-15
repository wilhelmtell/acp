#include <catch/catch.hpp>
#include "variables_map.hh"
#include "directory.hh"
#include <acp/verify.hh>
#include <acp/verify_error.hh>
#include <vector>
#include <string>

namespace test = acp::test;

TEST_CASE( "verify/target directory/not existing throws", "" ) {
    test::variables_map vm;
    vm["target_directory"] = std::string("directory_0");
    REQUIRE_THROWS_AS(
        acp::verify(vm),
        acp::target_directory_not_found
    );
}

TEST_CASE( "verify/target directory/multiple targets throw", "" ) {
    test::variables_map vm;
    vm["target_directory"] = "directory_0";
    vm["target_file"] = "file_0";
    REQUIRE_THROWS_AS(
        acp::verify(vm),
        acp::target_count
    );
}

TEST_CASE( "verify/source files/not empty", "" ) {
    test::variables_map vm;
    test::directory directory;
    vm["target_directory"] = directory.path().string();
    REQUIRE_THROWS_AS(
        acp::verify(vm),
        acp::source_files_count
    );
}

TEST_CASE( "verify/source files/all exist", "" ) {
    test::variables_map vm;
    test::directory directory;
    vm["target_directory"] = directory.path().string();
    vm["source_files"] = std::vector<std::string>({ "file_0" });
    REQUIRE_THROWS_AS(
        acp::verify(vm),
        acp::source_files_not_found
    );
}

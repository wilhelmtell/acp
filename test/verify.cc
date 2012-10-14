#include <catch/catch.hpp>
#include "variables_map.hh"
#include <acp/verify.hh>
#include <acp/verify_error.hh>
#include <vector>
#include <string>

namespace test = acp::test;

TEST_CASE( "verify/source files/all exist", "" ) {
    test::variables_map vm;
    vm["source_files"] = std::vector<std::string>({ "file_0" });
    REQUIRE_THROWS_AS(
        acp::verify_source_files(vm),
        acp::source_files_not_found
    );
}

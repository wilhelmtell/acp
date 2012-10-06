#include <catch/catch.hpp>
#include "paths.hh"
#include "directory.hh"
#include <acp/cp.hh>
#include <boost/filesystem/operations.hpp>

namespace fs = boost::filesystem;

TEST_CASE( "cp/copy a bunch of files", "" ) {
    acp::test::paths const paths(5);
    acp::test::directory const target_directory;
    acp::cp const op(paths.begin(), paths.end(), target_directory.path());
    for( auto const& path : paths )
        REQUIRE( fs::is_regular_file(path) );
}

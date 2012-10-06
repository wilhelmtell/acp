#include <catch/catch.hpp>
#include "file.hh"
#include "directory.hh"
#include <acp/cp.hh>
#include <boost/filesystem/operations.hpp>
#include <vector>
#include <boost/iterator/transform_iterator.hpp>
#include <functional>

namespace fs = boost::filesystem;

TEST_CASE( "cp/copy a bunch of files", "" ) {
    using acp::test::file;
    std::vector<file> const files(5);
    auto const file_to_path(std::bind(&file::path, std::placeholders::_1));
    acp::test::directory const directory;
    auto const files_b(files.begin()), files_e(files.end());
    auto const paths_b(boost::make_transform_iterator(files_b, file_to_path));
    auto const paths_e(boost::make_transform_iterator(files_e, file_to_path));
    acp::cp const op(paths_b, paths_e, directory.path());
    for( auto const& f : files )
        REQUIRE( fs::is_regular_file(directory.path() / f.path().filename()) );
}

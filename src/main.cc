#include "cmdline.hh"
#include "cp.hh"
#include <iostream>
#include <boost/filesystem/operations.hpp>
#include <exception>
#include <algorithm>
#include <boost/algorithm/string/join.hpp>

namespace fs = boost::filesystem;
namespace al = boost::algorithm;

namespace {
void verify_there_is_at_least_one_argument_file(std::vector<std::string> args)
{
    if( args.empty() )
        throw std::runtime_error("no files specified");
}

void verify_all_argument_files_exist(std::vector<std::string> args)
{
    auto const args_b(args.begin()), args_e(args.end());
    auto const pivot(std::partition(args_b, args_e, [](std::string const& a) {
        return fs::exists(a);
    }));
    if( pivot != args_e ) {
        std::vector<std::string> const files(pivot, args_e);
        throw std::runtime_error(al::join(files, ", ") + " not found");
    }
}

void verify(acp::cmdline const& conf)
{
    verify_there_is_at_least_one_argument_file(conf.args);
    verify_all_argument_files_exist(conf.args);
}
}  // local namespace

int main(int argc, char const * argv[])
{
    try {
        acp::cmdline conf(argc, argv);
        auto * out(conf.v ? &std::cout : nullptr);
        verify(conf);
        acp::cp op(conf.args.begin(), conf.args.end(), conf.tgt, out);
        op.commit();
        return 0;
    } catch( std::exception const& e ) {
        std::cerr << "error: " << e.what() << "\n"
                     "\n"
                     " usage: " << argv[0] << " src0 [src1 [...]] tgt\n"
                     "\n"
                     "src0, ... are file or directory names.\n"
                     "tgt       is a directory name.\n"
                     "\n"
                     "copy the given source files and directories into the\n"
                     "target directory. this is an all-or-nothing operation:\n"
                     "either all files successfully copy or none at all\n"
                     "copy.\n";
        return 1;
    }
}

#include "commandline.hh"
#include "cp.hh"
#include "verify.hh"
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <vector>
#include <string>
#include <iostream>

namespace po = boost::program_options;

namespace acp {
po::options_description options_description()
{
    po::options_description desc;
    desc.add_options()
        ("help", "display this help message")
        ("verbose,v", "describe what's being done")
        ("source_files", po::value<std::vector<std::string>>(), "files to copy")
        ("target_directory", po::value<std::string>(), "directory to copy into");
    return desc;
}

po::variables_map variables_map(int argc, char const * argv[],
                                po::options_description const& desc)
{
    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).
              options(desc).
              run(), vm);
    po::notify(vm);
    return vm;
}

void print_help(std::string const& argv0, po::options_description const& desc)
{
    std::cout <<
        " usage: " << argv0 << " [options]\n"
        "\n"
        " Copy source files and directories in an all-or-nothing fashion.\n"
        " Either all files successfully copy, or (in case of an error) none\n"
        " at all copy." <<
        "\n\n" <<
        desc;
}

void exec(po::variables_map const& vm)
{
    acp::verify(vm);
    auto const out(vm.count("verbose") ? &std::cout : nullptr);
    auto const source_files(vm["source_files"].as<std::vector<std::string>>());
    auto const target(vm["target_directory"].as<std::string>());
    acp::cp op(source_files.begin(), source_files.end(), target, out);
    op.commit();
}
}  // namespace acp

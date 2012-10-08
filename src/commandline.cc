#include "commandline.hh"
#include "cp.hh"
#include <boost/program_options.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/algorithm/string/join.hpp>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

namespace po = boost::program_options;
namespace fs = boost::filesystem;
namespace al = boost::algorithm;

namespace acp {
po::options_description options_description()
{
    po::options_description desc;
    desc.add_options()
        ("help", "display this help message")
        ("verbose,v", "describe what's being done")
        ("source-files", po::value<std::vector<std::string>>(), "files to copy")
        ("target", po::value<std::string>(), "target directory");
    return desc;
}

po::positional_options_description positional_options()
{
    po::positional_options_description positional;
    positional.add("target", 1).add("source-files", -1);
    return positional;
}

po::variables_map variables_map(int argc, char const * argv[],
                                po::positional_options_description const& pos,
                                po::options_description const& desc)
{
    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).
              options(desc).
              positional(pos).
              run(), vm);
    return vm;
}

void verify_source_files(po::variables_map const& vm)
{
    if( ! vm.count("source-files") )
        throw std::runtime_error("no source files specified");
    auto src(vm["source-files"].as<std::vector<std::string>>());
    auto const src_b(src.begin()), src_e(src.end());
    auto const pivot(std::partition(src_b, src_e, [](std::string const& s) {
        return fs::exists(s);
    }));
    if( pivot != src_e ) {
        std::vector<std::string> const files(pivot, src_e);
        throw std::runtime_error(al::join(files, ", ") + " not found");
    }
}

void verify_target_directory(po::variables_map const& vm)
{
    if( ! vm.count("target") )
        throw std::runtime_error("no target directory specified");
    if( ! fs::is_directory(vm["target"].as<std::string>()) )
        throw std::runtime_error("target directory not found");
}

void verify(po::variables_map const& vm)
{
    verify_target_directory(vm);
    verify_source_files(vm);
}

void print_help(std::string const& argv0, po::options_description const& desc)
{
    std::cout <<
        " usage: " << argv0 << " [options] t s0 [s1 [...]]\n"
        "\n"
        "t          is a directory name.\n"
        "s0, s1 ... are file or directory names.\n"
        "\n"
        "copy source files and directories s0, s1, ... into\n"
        "target directory t. this is an all-or-nothing\n"
        "operation: either all files successfully copy or none\n"
        "at all copy."
    << "\n\n" << desc << '\n';
}

void exec(po::variables_map const& vm)
{
    verify(vm);
    auto const out(vm.count("verbose") ? &std::cout : nullptr);
    auto const source_files(vm["source-files"].as<std::vector<std::string>>());
    auto const target(vm["target"].as<std::string>());
    acp::cp op(source_files.begin(), source_files.end(), target, out);
    op.commit();
}
}  // namespace acp

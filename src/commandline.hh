#ifndef ACP_COMMANDLINE_HH_
#define ACP_COMMANDLINE_HH_

#include <boost/program_options.hpp>
#include <string>

namespace acp {
boost::program_options::options_description options_description();

boost::program_options::positional_options_description positional_options();

boost::program_options::variables_map
variables_map(int argc, char const * argv[],
              boost::program_options::positional_options_description const& pos,
              boost::program_options::options_description const& desc);

void verify_source_files(boost::program_options::variables_map const& vm);
void verify_target_directory(boost::program_options::variables_map const& vm);
void verify(boost::program_options::variables_map const& vm);

void exec(boost::program_options::variables_map const& vm);

void print_help(std::string const& argv0,
                boost::program_options::options_description const& desc);

}  // namespace acp

#endif  // ACP_COMMANDLINE_HH_

#ifndef ACP_CMDLINE_HH_
#define ACP_CMDLINE_HH_

#include <vector>
#include <string>

namespace acp {
struct cmdline {
    cmdline(int const argc, char const * argv[]);

public:
    std::vector<std::string> args;
    std::string tgt;
    bool v;
};
}  // namespace acp

#endif  // ACP_CMDLINE_HH_

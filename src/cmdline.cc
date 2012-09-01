#include "cmdline.hh"
#include <vector>
#include <string>

namespace acp {
cmdline::cmdline(int const argc, char const * argv[])
: tgt(argv[argc - 1])
, v(false)
{
    args.reserve(argc - 1);
    for( auto i(1); i < argc - 1; ++i ) {
        std::string arg(argv[i]);
        if( arg == "-v" || arg == "--verbose" )
            v = true;
        else
            args.push_back(arg);
    }
}

bool cmdline::ok() const
{
    return ! args.empty();
}
}  // namespace acp

#include <iostream>
#include <exception>
#include "commandline.hh"

int main(int argc, char const * argv[])
{
    try {
        auto const desc(acp::options_description());
        auto const positional(acp::positional_options());
        auto const vm(acp::variables_map(argc, argv, positional, desc));
        if( vm.count("help") )
            acp::print_help(argv[0], desc);
        else
            acp::exec(vm);
        return 0;
    } catch( std::exception const& e ) {
        std::cerr << "error: " << e.what() << '\n';
        return 1;
    }
}

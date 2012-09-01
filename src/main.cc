#include "cp_file.hh"
#include "cmdline.hh"
#include <stack>
#include <iostream>
#include <algorithm>
#include <string>
#include <exception>
#include <boost/filesystem/path.hpp>

namespace bfs = boost::filesystem;

int main(int argc, char const * argv[])
{
    acp::cmdline conf(argc, argv);
    if( ! conf.ok() ) {
        std::cout << " usage: " << argv[0] << " src0 [src1 [src2 [...]]] tgt\n";
        return 0;
    }
    std::stack<acp::cp_file> ops;
    auto * out(conf.v ? &std::cout : nullptr);
    try {
        std::for_each(conf.args.begin(), conf.args.end(), [&](std::string const& f) {
            ops.push(acp::cp_file(f, bfs::path(conf.tgt) / f, out));
        });
        while( ! ops.empty() ) {  // std::stack elements cleanup order undefined
            ops.top().commit();
            ops.pop();
        }
    } catch( std::exception const& e ) {
        std::cerr << "error: " << e.what() << '\n';
        if( conf.v && ! ops.empty() )
            (*out) << "rolling back ...\n";
        while( ! ops.empty() )  // std::stack elements cleanup order undefined
            ops.pop();
    }
    return 0;
}

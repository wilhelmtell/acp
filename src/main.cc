#include "cmdline.hh"
#include "cp.hh"
#include <iostream>
#include <exception>

int main(int argc, char const * argv[])
{
    acp::cmdline conf(argc, argv);
    if( ! conf.ok() ) {
        std::cout << " usage: " << argv[0] << " src0 [src1 [src2 [...]]] tgt\n";
        return 0;
    }
    auto * out(conf.v ? &std::cout : nullptr);
    try {
        acp::cp op(conf.args.begin(), conf.args.end(), conf.tgt, out);
        op.commit();
    } catch( std::exception const& e ) {
        std::cerr << "error: " << e.what() << '\n';
    }
    return 0;
}

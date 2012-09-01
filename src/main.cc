#include "cp_file.hh"
#include "cmdline.hh"
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

int main(int argc, char const * argv[])
{
    acp::cmdline conf(argc, argv);
    if( ! conf.ok() ) {
        std::cout << " usage: " << argv[0] << " src0 [src1 [src2 [...]]] tgt\n";
        return 0;
    }
    std::vector<acp::cp_file> ops;
    std::ostream * out(conf.v ? &std::cout : nullptr);
    std::for_each(conf.args.begin(), conf.args.end(), [&](std::string const& f) {
        ops.push_back(acp::cp_file(f, conf.tgt, out));
    });
    std::for_each(ops.begin(), ops.end(), [](acp::cp_file& op) {
        op.commit();
    });
    return 0;
}

#include "cp.hh"
#include <algorithm>
#include "cp_file.hh"

namespace acp {
cp::~cp()
{
    while( ! ops.empty() )
        ops.pop_back();
}

void cp::commit()
{
    std::for_each(ops.begin(), ops.end(), [](cp_file& op) {
        op.commit();
    });
}
}  // namespace acp

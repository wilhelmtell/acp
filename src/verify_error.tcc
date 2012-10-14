#ifndef ACP_VERIFY_ERROR_TCC_
#define ACP_VERIFY_ERROR_TCC_

#include "verify_error.hh"
#include <vector>
#include <string>
#include <boost/algorithm/string/join.hpp>
#include <cassert>

namespace acp {
template<typename In>
source_files_not_found::source_files_not_found(In files_b, In files_e)
: runtime_error("source files " +
                boost::algorithm::join(std::vector<std::string>(files_b, files_e), ", ") +
                " not found")
{
    assert( files_b != files_e );
}
}  // namespace acp

#endif  // ACP_VERIFY_ERROR_TCC_

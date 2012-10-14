#include "verify_error.hh"

namespace acp {
source_files_count::source_files_count()
: runtime_error("no source files specified")
{
}
}  // namespace acp

#include "verify_error.hh"

namespace acp {
source_files_count::source_files_count()
: runtime_error("no source files specified")
{
}

target_count::target_count()
: runtime_error("exactly one target must be specified")
{
}

target_directory_not_found::target_directory_not_found()
: runtime_error("target directory not found")
{
}
}  // namespace acp

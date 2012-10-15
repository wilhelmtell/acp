#ifndef ACP_VERIFY_ERROR_HH_
#define ACP_VERIFY_ERROR_HH_

#include <stdexcept>
#include <string>

namespace acp {
struct source_files_count : std::runtime_error {
    source_files_count();
};

struct source_files_not_found : std::runtime_error {
    template<typename In>
    source_files_not_found(In files_b, In files_e);
};

struct target_count : std::runtime_error {
    target_count();
};
}  // namespace acp

#include "verify_error.tcc"

#endif  // ACP_VERIFY_ERROR_HH_

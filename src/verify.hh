#ifndef ACP_VERIFY_HH_
#define ACP_VERIFY_HH_

namespace acp {
template<typename I>
void verify_source_files(I const& vm);

template<typename I>
void verify_target(I const& vm);

template<typename I>
void verify_target_directory(I const& vm);

template<typename I>
void verify(I const& vm);
}  // namespace acp

#include "verify.tcc"

#endif  // ACP_VERIFY_HH_

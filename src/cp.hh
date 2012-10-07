#ifndef ACP_CP_HH_
#define ACP_CP_HH_

#include "cp_file.hh"
#include <iosfwd>
#include <vector>

namespace acp {
struct cp {
    template<typename In>
    cp(In first, In last,
       boost::filesystem::path target_dir,
       std::ostream * out = nullptr);
    ~cp();
    cp(cp&&) = default;
    cp& operator=(cp&&) = default;

    void commit();

private:
    std::vector<cp_file> ops;
};
}  // namespace acp

#include "cp.tcc"

#endif  // ACP_CP_HH_

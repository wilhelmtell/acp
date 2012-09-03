#ifndef ACP_CP_HH_
#define ACP_CP_HH_

#include "cp_file.hh"
#include <string>
#include <iosfwd>
#include <vector>

namespace acp {
struct cp {
    template<typename In>
    cp(In const& first, In const& last,
       std::string const& target_dir,
       std::ostream * out = nullptr);

    ~cp();
    cp(cp&&) = default;
    cp& operator=(cp&&) = default;
    cp(cp const&) = delete;
    cp& operator=(cp const&) = delete;

    void commit();

private:
    std::vector<cp_file> ops;
};
}  // namespace acp

#include "cp.tcc"

#endif  // ACP_CP_HH_

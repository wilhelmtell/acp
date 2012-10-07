#ifndef ACP_CP_TCC_
#define ACP_CP_TCC_

#include <algorithm>
#include <boost/filesystem/operations.hpp>
#include <iosfwd>
#include "cp_file.hh"
#include <boost/filesystem/path.hpp>

namespace acp { namespace detail {
inline void cp_r(boost::filesystem::path const& d,
                 boost::filesystem::path const& t,
                 std::vector<acp::cp_file>& ops,
                 std::ostream * out)
{
    typedef boost::filesystem::directory_iterator dir_iter;
    typedef boost::filesystem::directory_entry dir_entry;
    std::for_each(dir_iter(d), dir_iter(), [&](dir_entry const& entry) {
        auto const path(entry.path());
        auto const as(t / path.filename());
        ops.push_back(acp::cp_file(path, as, out));
        if( boost::filesystem::is_directory(path) )
            cp_r(path, as, ops, out);
    });
}
} }  // namespace acp::detail

namespace acp {
template<typename In>
cp::cp(In first, In last,
       boost::filesystem::path target_dir,
       std::ostream * out)
{
    std::for_each(first, last, [&](boost::filesystem::path const& p) {
        auto const as(target_dir / p.filename());
        this->ops.push_back(cp_file(p, as, out));
        if( boost::filesystem::is_directory(p) )
            detail::cp_r(p, as, this->ops, out);
    });
}
}  // namespace acp

#endif  // ACP_CP_TCC_

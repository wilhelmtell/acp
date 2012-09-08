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
    namespace bfs = boost::filesystem;
    typedef bfs::directory_iterator di;
    std::for_each(di(d), di(), [&](bfs::directory_entry const& de) {
        auto const p(de.path());
        auto const as(t / p.filename());
        ops.push_back(acp::cp_file(p, as, out));
        if( bfs::is_directory(p) )
            cp_r(p, as, ops, out);
    });
}
} }  // namespace acp::detail

namespace acp {
template<typename In>
cp::cp(In const& first, In const& last,
       boost::filesystem::path const& target_dir,
       std::ostream * out)
{
    namespace bfs = boost::filesystem;
    std::for_each(first, last, [&](bfs::path const& p) {
        auto const as(target_dir / p.filename());
        this->ops.push_back(cp_file(p, as, out));
        if( bfs::is_directory(p) )
            detail::cp_r(p, as, this->ops, out);
    });
}
}  // namespace acp

#endif  // ACP_CP_TCC_

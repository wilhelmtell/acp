#include "cp_file.hh"
#include <boost/filesystem/operations.hpp>
#include <boost/system/error_code.hpp>

namespace bfs = boost::filesystem;

namespace acp {
cp_file::cp_file(std::string const& s, std::string const& t, std::ostream * out)
: t(t)
, ok(false)
, out(out)
{
    if( out != nullptr )
        (*out) << s << " -> " << t << '\n';
    bfs::copy(s, t);
}

cp_file::~cp_file()
{
    if( ! ok ) {
        if( out != nullptr )
            (*out) << "rm " << t << '\n';
        boost::system::error_code e;
        bfs::remove(t, e);
    }
}

void cp_file::commit()
{
    ok = true;
}
}  // namespace acp

#include "cp_file.hh"
#include <boost/filesystem/operations.hpp>
#include <boost/system/error_code.hpp>
#include <ostream>

namespace bfs = boost::filesystem;

namespace acp {
cp_file::cp_file(std::string const& s, std::string const& t, std::ostream * out)
: t(t)
, ok(false)
, out(out)
{
    bfs::copy(s, t);
    if( out != nullptr )
        (*out) << "cp " << s << " " << t << '\n';
}

cp_file::~cp_file()
{
    if( ! ok && ! t.empty() ) {
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

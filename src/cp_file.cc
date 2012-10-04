#include "cp_file.hh"
#include <boost/filesystem/operations.hpp>
#include <boost/system/error_code.hpp>
#include <boost/filesystem/path.hpp>
#include <ostream>

namespace bfs = boost::filesystem;

namespace acp {
cp_file::cp_file(bfs::path s, bfs::path t, std::ostream * out)
: t(t)
, ok(false)
, out(out)
{
    bfs::copy(s, t);
    if( out != nullptr )
        (*out) << "cp " << s.string() << " " << t.string() << '\n';
}

cp_file::~cp_file()
{
    if( ! ok && ! t.empty() ) {
        if( out != nullptr )
            (*out) << "rm " << t.string() << '\n';
        boost::system::error_code e;
        bfs::remove(t, e);
    }
}

void cp_file::commit()
{
    ok = true;
}
}  // namespace acp

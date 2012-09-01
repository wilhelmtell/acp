#include "cp_file.hh"
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/system/error_code.hpp>

namespace bfs = boost::filesystem;

namespace acp {
cp_file::cp_file(boost::filesystem::path const& s,
                 boost::filesystem::path const& t,
                 std::ostream * out)
: t(t)
, ok(false)
, out(out)
{
    if( out != nullptr )
        *out << s.string() << " -> " << t.string() << '\n';
    bfs::copy(s, t);
}

cp_file::~cp_file()
{
    if( ! ok ) {
        if( out != nullptr )
            *out << "rm " << t.string() << '\n';
        boost::system::error_code e;
        bfs::remove(t, e);
    }
}

void cp_file::commit()
{
    ok = true;
}
}  // namespace acp

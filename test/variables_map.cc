#include "variables_map.hh"
#include <string>
#include <cassert>

namespace acp { namespace test {
int variables_map::count(std::string k) const
{
    return m.find(k) != m.end();
}

variable const& variables_map::operator[](std::string k) const
{
    assert( m.find(k) != m.end() );
    return m.find(k)->second;
}

variable& variables_map::operator[](std::string k)
{
    return m[k];
}
} }  // namespace acp::test

#ifndef ACP_TEST_VARIABLES_MAP_HH_
#define ACP_TEST_VARIABLES_MAP_HH_

#include <string>
#include <map>
#include "variable.hh"

namespace acp { namespace test {
struct variables_map {
    int count(std::string k) const;
    variable const& operator[](std::string k) const;
    variable& operator[](std::string k);

    std::map<std::string,variable> m;
};
} }  // namespace acp::test

#endif  // ACP_TEST_VARIABLES_MAP_HH_

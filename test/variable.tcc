#ifndef ACP_TEST_VARIABLE_TCC_
#define ACP_TEST_VARIABLE_TCC_

#include "variables_map.hh"
#include <boost/any.hpp>

namespace acp { namespace test {
template<typename T>
variable::variable(T value)
: value(value)
{
}

template<typename T>
T variable::as() const
{
    return boost::any_cast<T>(value);
}
} }  // namespace acp::test

#endif  // ACP_TEST_VARIABLE_TCC_

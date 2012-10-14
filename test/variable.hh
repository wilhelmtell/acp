#ifndef ACP_TEST_VARIABLE_HH_
#define ACP_TEST_VARIABLE_HH_

#include <boost/any.hpp>

namespace acp { namespace test {
struct variable {
    variable();
    template<typename T>
    variable(T value);

    template<typename T>
    T as() const;

public:
    boost::any value;
};
} }  // namespace acp::test

#include "variable.tcc"

#endif  // ACP_TEST_VARIABLE_HH_

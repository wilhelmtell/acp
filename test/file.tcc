#ifndef ACP_TEST_FILE_TCC_
#define ACP_TEST_FILE_TCC_

#include <fstream>

namespace acp { namespace test {
template<typename T>
file& operator<<(file& f, T const& value)
{
    std::ofstream out(f.path().string());
    out << value;
    return f;
}
} }  // namespace acp::test

#endif  // ACP_TEST_FILE_TCC_

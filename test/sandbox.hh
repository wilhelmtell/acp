#ifndef ACP_TEST_SANDBOX_HH_
#define ACP_TEST_SANDBOX_HH_

#include <boost/filesystem/path.hpp>

namespace acp { namespace test {
struct sandbox {
    sandbox();
    ~sandbox();
    sandbox(sandbox&&) = delete;
    sandbox& operator=(sandbox&&) = delete;
    sandbox(sandbox const&) = delete;
    sandbox& operator=(sandbox const&) = delete;

    boost::filesystem::path path() const;

private:
    boost::filesystem::path directory;
};
} }  // namespace acp::test

#endif  // ACP_TEST_SANDBOX_HH_

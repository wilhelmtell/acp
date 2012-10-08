#ifndef ACP_TEST_CONTENTS_OF_HH_
#define ACP_TEST_CONTENTS_OF_HH_

#include <boost/filesystem/path.hpp>

namespace acp { namespace test { struct file; } }

namespace acp { namespace test {
struct contents_of {
    explicit contents_of(boost::filesystem::path const& p);
    explicit contents_of(file const& f);

    friend bool operator==(contents_of const& lhs, contents_of const& rhs);

private:
    boost::filesystem::path path;
};

bool operator==(contents_of const& lhs, contents_of const& rhs);
bool operator!=(contents_of const& lhs, contents_of const& rhs);
} }  // namespace acp::test

#endif  // ACP_TEST_CONTENTS_OF_HH_

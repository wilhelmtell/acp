#ifndef ACP_CP_FILE_HH_
#define ACP_CP_FILE_HH_

#include <string>
#include <iosfwd>
#include <boost/filesystem/path.hpp>

namespace acp {
struct cp_file {
    cp_file(boost::filesystem::path const& s,
            boost::filesystem::path const& t,
            std::ostream * out = nullptr);
    cp_file(cp_file const&) = delete;
    cp_file& operator=(cp_file const&) = delete;
    cp_file(cp_file&&) = default;
    cp_file& operator=(cp_file&&) = default;
    ~cp_file();

    void commit();

private:
    std::string t;
    bool ok;
    std::ostream * out;
};
}  // namespace acp

#endif  // ACP_CP_FILE_HH_

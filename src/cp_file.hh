#ifndef ACP_CP_FILE_HH_
#define ACP_CP_FILE_HH_

#include <string>
#include <iosfwd>
#include <boost/filesystem/path.hpp>

namespace acp {
struct cp_file {
    cp_file(boost::filesystem::path s,
            boost::filesystem::path t,
            std::ostream * out = nullptr);
    cp_file(cp_file&& rhs);
    cp_file& operator=(cp_file&& rhs);
    ~cp_file();

    void commit();

private:
    boost::filesystem::path t;
    bool ok;
    std::ostream * out;
};
}  // namespace acp

#endif  // ACP_CP_FILE_HH_

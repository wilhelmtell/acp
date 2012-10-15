#ifndef ACP_VERIFY_TCC_
#define ACP_VERIFY_TCC_

#include "verify.hh"
#include "verify_error.hh"
#include <string>
#include <vector>
#include <algorithm>
#include <boost/filesystem/operations.hpp>
#include <boost/algorithm/string/join.hpp>

namespace acp { namespace detail {
template<typename I>
void verify_source_files_count(I const& vm)
{
    if( ! vm.count("source_files") )
        throw acp::source_files_count();
}

template<typename I>
void verify_source_files_all_exist(I const& vm)
{
    auto src(vm["source_files"].template as<std::vector<std::string>>());
    auto const src_b(begin(src)), src_e(end(src));
    auto const pivot(partition(src_b, src_e, [](std::string const& s) {
        return boost::filesystem::exists(s);
    }));
    if( pivot != src_e )
        throw acp::source_files_not_found(pivot, src_e);
}

template<typename I>
void verify_source_files(I const& vm)
{
    detail::verify_source_files_count(vm);
    detail::verify_source_files_all_exist(vm);
}

template<typename I>
void verify_one_target_specified(I const& vm)
{
    if( vm.count("target_directory") + vm.count("target_file") != 1 )
        throw acp::target_count();
}

template<typename I>
void verify_target_directory_exists(I const& vm)
{
    auto const target(vm["target_directory"].template as<std::string>());
    if( ! boost::filesystem::exists(target) )
        throw acp::target_directory_not_found();
}

template<typename I>
void verify_target_directory_is_a_directory(I const& vm)
{
    auto const target(vm["target_directory"].template as<std::string>());
    if( ! boost::filesystem::is_directory(target) )
        throw acp::target_directory_is_not_a_directory();
}

template<typename I>
void verify_target_directory(I const& vm)
{
    verify_target_directory_exists(vm);
    verify_target_directory_is_a_directory(vm);
}

template<typename I>
void verify_target(I const& vm)
{
    verify_one_target_specified(vm);
    if( vm.count("target_directory") )
        verify_target_directory(vm);
}
} }  // namespace acp::detail


namespace acp {
template<typename I>
void verify(I const& vm)
{
    detail::verify_target(vm);
    detail::verify_source_files(vm);
}
}  // namespace acp

#endif  // ACP_VERIFY_TCC_

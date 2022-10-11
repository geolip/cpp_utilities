#ifndef COMPOUND_KEY_H
#define COMPOUND_KEY_H

#include <tuple>
#include <type_traits>
#include <functional>
#include <utility>
#include <algorithm>

namespace cpp_utils {

template<typename... Args>
using compound_key = std::tuple<Args...>;

struct prefix_compare
{
    using is_transparent = void;

    template<typename Tuple0, typename Tuple1>
    bool operator() (const Tuple0& lhs, const Tuple1& rhs) const
    {
        constexpr size_t min_dimension = std::min(std::tuple_size_v<Tuple0>, std::tuple_size_v<Tuple1>);
        return comp(lhs, rhs, std::make_index_sequence<min_dimension>());
    }

private:

    template<typename Tuple0, typename Tuple1, std::size_t... ids>
    bool comp(const Tuple0& lhs, const Tuple1& rhs, const std::index_sequence<ids...>&) const
    {
        return std::forward_as_tuple(std::get<ids>(lhs)...) < std::forward_as_tuple(std::get<ids>(rhs)...);
    }
};

}

#endif
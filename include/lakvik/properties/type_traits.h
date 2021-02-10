#pragma once
#include <type_traits>
namespace lakvik::properties
{
    template<typename... args>
    struct always_false : std::false_type
    {
        
    };
    template<typename... args>
    constexpr bool always_false_v = always_false<args...>::value;
}
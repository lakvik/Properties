#pragma once
#include "lakvik/properties/type_traits.h"
namespace lakvik::properties
{
    template<typename... args>
    struct parameter_pack
    {
        template<typename t = void>
        parameter_pack()
        {
            static_assert(always_false_v<t>,"parameter_pack is for compile time use only");
        }
        
        template<template<typename...> typename t>
        using apply_to = t<args...>;
    };
}
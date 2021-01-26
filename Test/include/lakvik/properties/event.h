#pragma once
#include "lakvik/properties/parameter_pack.h"
#include <functional>
namespace lakvik::properties
{
    template<typename... args>
    class event
    {
    public:
        using arguments = parameter_pack<args...>;
        virtual ~event() = default;
        using id = unsigned;
        using callback = std::function<void(args...)>;
        virtual id add(callback&& function) = 0;
        virtual void remove(id value) = 0;
    };
}
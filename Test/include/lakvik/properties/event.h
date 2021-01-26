#pragma once
#include <functional>
namespace lakvik::properties
{
    template<typename... Args>
    class event
    {
    public:
        virtual ~event() = default;
        using id = unsigned;
        using callback = std::function<void(Args...)>;
        virtual id add(callback&& function) = 0;
        virtual void remove(id value) = 0;
    };
}
#pragma once
#include "lakvik/properties/event.h"
#include <mutex>
#include <unordered_map>
#include <cassert>
namespace lakvik::properties
{
    template<typename... args>
    class threadsafe_event : public event<args...>
    {
    private:
        using super = event<args...>;
        using id = super::id;
        using callback = super::callback;
    public:
        threadsafe_event() = default;
        ~threadsafe_event() override = default;
        id add(callback&& function) override
        {
            std::lock_guard guard(lock);
            id_to_callback.emplace(next_id,std::move(function));
            return next_id++;
        }
        void remove(id value) override
        {
            std::lock_guard guard(lock);
            auto count = id_to_callback.erase(value);
            assert(count == 1);
        }
    private:
        id next_id = 0;
        std::mutex lock;
        std::unordered_map<id,callback> id_to_callback;
    };
    template<typename t>
    using threadsafe_event_for = typename t::arguments::apply_to<threadsafe_event>;
}
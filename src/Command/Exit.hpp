#pragma once

#include <mutex>
#include <atomic>

#include "Command/Base.hpp"
#include "User/Host.hpp"

using std::atomic_bool;
using std::atomic_int;
using std::mutex;
using std::scoped_lock;

extern mutex m_exit_trigger; // mutex for : exit_trigger, exit_code

extern atomic_bool exit_trigger; // if true then the program will exit
extern atomic_int exit_code;     // the program will pass this value on exit

template <nullptr_t N>
class _ExitCommand final : public virtual _Command<N>, public virtual Callable<void, true, false, void>, public virtual _Object<N> {
    protected:
    int rv;

    public:
    _ExitCommand(_UserClass<N>* ptr, int i = 0) noexcept(true)
        : _Command<N>(ptr), rv(i) { }
    virtual bool has_trait(CommandFlags f) const volatile noexcept(true) final override { return f == CommandFlags::Exit; }
    virtual void operator()(void) noexcept(true) final override {
        if (this->usr == &host) {
            scoped_lock lk(m_exit_trigger);
            if (not exit_trigger)
                exit_trigger = true, exit_code = rv;
        }
    }
};

using ExitCommand = _ExitCommand<nullptr>;
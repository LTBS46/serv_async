#pragma once

template <nullptr_t>
class _Command;

#include "Callable.hpp"
#include "User/Observer.hpp"

// must be false for default state
enum class CommandFlags {
    Exit
};

template <nullptr_t N>
class _Command : public virtual Callable<void, true, false, void>, public virtual _Object<N> {
    protected:
    _UserClass<N>* usr;

    public:
    _Command(_UserClass<N>* ptr) noexcept(true) : usr(ptr) { }
    virtual bool has_trait(CommandFlags) volatile const noexcept(true) { return false; }
};

using Command = _Command<nullptr>;
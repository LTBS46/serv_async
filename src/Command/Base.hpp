#pragma once

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
    _Command(_UserClass<N>* ptr = N) noexcept(true) : usr(ptr not_eq N ? ptr : &observer) { }
    virtual bool has_trait(CommandFlags) volatile const noexcept(true) { return false; }
};

using Command = _Command<nullptr>;
#pragma once

#include "Callable.hpp"
#include "User/Observer.hpp"

template <nullptr_t N>
class _Command : public virtual Callable<void, true, false, void>, public virtual _Object<N>
{
protected:
    UserClass *usr;

public:
    _Command(_UserClass<N> *ptr = &observer) noexcept(true) : usr(ptr not_eq nullptr ? ptr : &observer) {}
    virtual bool is_exit(void) volatile const noexcept(true) { return false; }
};

using Command = _Command<nullptr>;
#pragma once

#include "Callable.hpp"
#include "User/Observer.hpp"

class Command : public virtual Callable<void, true, false, void>, public virtual Object
{
protected:
    UserClass *usr;

public:
    Command(UserClass * = &observer) noexcept(true);
    virtual bool is_exit(void) volatile const noexcept(true);
    virtual ~Command(void) noexcept(true);
};

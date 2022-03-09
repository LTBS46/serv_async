#pragma once

#include <mutex>
#include <atomic>

#include "Command/Base.hpp"

using std::atomic_bool;
using std::atomic_int;
using std::mutex;

class ExitCommand final : public virtual Command
{
protected:
    int rv;

public:
    ExitCommand(UserClass *, int = 0) noexcept(true);
    virtual bool is_exit(void) const volatile noexcept(true) final override;
    virtual void operator()(void) noexcept(true) final override;
};

extern mutex m_exit_trigger; // mutex for : exit_trigger, exit_code

extern atomic_bool exit_trigger; // if true then the program will exit
extern atomic_int exit_code;     // the program will pass this value on exit
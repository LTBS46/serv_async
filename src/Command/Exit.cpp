#include "Command/Exit.hpp"
#include "User/Host.hpp"
using std::scoped_lock;

ExitCommand::ExitCommand(UserClass *ptr, int i) noexcept(true)
    : Command(ptr), rv(i) {}

bool ExitCommand::is_exit(void) const volatile noexcept(true) { return true; }

void ExitCommand::operator()(void) noexcept(true)
{
    if (usr == &host)
    {
        scoped_lock lk(m_exit_trigger);
        if (not exit_trigger)
            exit_trigger = true, exit_code = rv;
    }
}

atomic_bool exit_trigger = false;
atomic_int exit_code = 0;
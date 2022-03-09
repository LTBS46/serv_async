#include "Command/Log.hpp"

using std::endl;
using std::scoped_lock;

void LogCommand::operator()(void) noexcept(true)
{
    if (usr->get_admin_level() != AdminLevel::Passerby)
    {
        scoped_lock lk(*(output->get_output_mutex()));
        *output->get_output_stream() << s << endl;
    }
}

LogCommand::LogCommand(UserClass *ptr, const string &__s,
                       UserClass *__o) noexcept(true)
    : Command(ptr), s(__s), output(__o) {}
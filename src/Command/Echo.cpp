#include "Command/Echo.hpp"

EchoCommand::EchoCommand(UserClass *ptr, const string &s) noexcept(true)
    : Command(ptr), LogCommand(ptr, s, ptr) {}



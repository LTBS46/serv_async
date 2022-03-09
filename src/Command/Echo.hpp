#pragma once

#include "Command/Log.hpp"

class EchoCommand : public virtual LogCommand
{
public:
    EchoCommand(UserClass *, const string &) noexcept(true);
};

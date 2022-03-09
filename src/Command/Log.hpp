#pragma once

#include <string>

#include "Command/Base.hpp"

using std::string;

class LogCommand : public virtual Command
{
protected:
    string s;
    UserClass *output;

public:
    LogCommand(UserClass *, const string &, UserClass *) noexcept(true);
    virtual void operator()(void) noexcept(true) final override;
};

#pragma once

#include <exception>

#include "Command/Log.hpp"

using std::exception;

class ErrorCommand : public virtual LogCommand
{
public:
    ErrorCommand(UserClass *, const exception &) noexcept(true);
};

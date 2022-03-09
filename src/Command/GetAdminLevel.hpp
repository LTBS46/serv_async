#pragma once

#include "Command/Echo.hpp"

class GetAdminLevelCommand : public virtual EchoCommand
{
protected:
    GetAdminLevelCommand(UserClass *, AdminLevel) noexcept(true);

public:
    GetAdminLevelCommand(UserClass *) noexcept(true);
    GetAdminLevelCommand(UserClass *, UserClass *) noexcept(true);
};
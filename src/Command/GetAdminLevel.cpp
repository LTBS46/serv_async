#include "Command/GetAdminLevel.hpp"

GetAdminLevelCommand::GetAdminLevelCommand(UserClass *u, AdminLevel a) noexcept(true)
    : Command(u),
      LogCommand(u, admin_level_to_string(a), u),
      EchoCommand(u, admin_level_to_string(a)) {}

GetAdminLevelCommand::GetAdminLevelCommand(UserClass *u) noexcept(true)
    : GetAdminLevelCommand(u, u) {}

GetAdminLevelCommand::GetAdminLevelCommand(UserClass *u1,
                                           UserClass *u2) noexcept(true)
    : GetAdminLevelCommand(u1, u2->get_admin_level()) {}
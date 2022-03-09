
#include <iostream>

#include "User/Base.hpp"

string admin_level_to_string(AdminLevel a) noexcept(true)
{
    // using enum AdminLevel;
    switch (a)
    {
    case AdminLevel::Host:
        return "Host";
    case AdminLevel::Admin:
        return "Admin";
    case AdminLevel::User:
        return "User";
    case AdminLevel::Passerby:
        return "Passerby";
    default:
        return "Invalid";
    }
}

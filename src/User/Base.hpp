#pragma once

#include <ostream>
#include <mutex>
#include <string>

#include "Object.hpp"

using std::mutex;
using std::ostream;
using std::string;

enum class AdminLevel
{
    Host,
    Admin,
    User,
    Passerby
};

class UserClass : public virtual Object
{
public:
    constexpr UserClass(void) noexcept(true) = default;
    UserClass(const UserClass &) noexcept(true) = delete;
    UserClass(UserClass &&) noexcept(true) = delete;
    virtual UserClass &operator=(const UserClass &) noexcept(true) = delete;
    virtual UserClass &operator=(UserClass &&) noexcept(true) = delete;
    virtual ~UserClass(void) noexcept(true);
    virtual AdminLevel get_admin_level(void) const noexcept(true) = 0;
    virtual mutex *get_output_mutex(void) noexcept(true) = 0;
    virtual ostream *get_output_stream(void) noexcept(true) = 0;
};

string admin_level_to_string(AdminLevel) noexcept(true);
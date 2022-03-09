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

template <nullptr_t N>
class _UserClass : public virtual _Object<N>
{
public:
    constexpr _UserClass(void) noexcept(true) {}
    _UserClass(const _UserClass &) noexcept(true) = delete;
    _UserClass(_UserClass &&) noexcept(true) = delete;
    virtual _UserClass &operator=(const _UserClass &) noexcept(true) = delete;
    virtual _UserClass &operator=(_UserClass &&) noexcept(true) = delete;
    virtual ~ _UserClass(void) noexcept(true) {}
    virtual AdminLevel get_admin_level(void) const noexcept(true) = 0;
    virtual mutex *get_output_mutex(void) noexcept(true) = 0;
    virtual ostream *get_output_stream(void) noexcept(true) = 0;
};

using UserClass = _UserClass<nullptr>;

string admin_level_to_string(AdminLevel) noexcept(true);
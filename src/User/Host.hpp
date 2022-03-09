#pragma once

#include "User/Base.hpp"

class Host final : public virtual UserClass
{
public:
    virtual mutex *get_output_mutex(void) noexcept(true) override final;
    virtual ostream *get_output_stream(void) noexcept(true) override final;
    virtual AdminLevel get_admin_level(void) const noexcept(true) override final;
};

extern mutex m_cout; // mutex for : cout
extern Host host;    // UserClass host
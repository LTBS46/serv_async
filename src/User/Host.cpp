#include "User/Host.hpp"

#include <iostream>

using std::cout;

mutex *Host::get_output_mutex(void) noexcept(true) { return &(m_cout); }

ostream *Host::get_output_stream(void) noexcept(true) { return &(cout); }

AdminLevel Host::get_admin_level(void) const noexcept(true)
{
    return AdminLevel::Host;
}

Host host;
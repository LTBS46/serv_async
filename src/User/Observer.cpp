#include "User/Observer.hpp"

mutex *Observer::get_output_mutex(void) noexcept(true) { return &(m_log_file); }

ofstream *Observer::get_output_stream(void) noexcept(true) { return &(log_file); }

AdminLevel Observer::get_admin_level(void) const noexcept(true)
{
    return AdminLevel::User;
}

Observer observer;
#pragma once

#include <fstream>

#include "User/Base.hpp"

using std::ofstream;

class Observer final : public virtual UserClass
{
public:
    virtual mutex *get_output_mutex(void) noexcept(true) override final;
    virtual ofstream *get_output_stream(void) noexcept(true) override final;
    virtual AdminLevel get_admin_level(void) const noexcept(true) override final;
};

extern ofstream log_file; // file to put the server log
extern mutex m_log_file;  // mutex for : log_file
extern Observer observer; // UserClass observer
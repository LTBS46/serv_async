#pragma once

#include <fstream>

#include "User/Base.hpp"

using std::ofstream;

extern ofstream log_file; // file to put the server log
extern mutex m_log_file;  // mutex for : log_file

template <nullptr_t N>
class _Observer final : public virtual _UserClass<N> {
    public:
    virtual mutex* get_output_mutex(void) noexcept(true) override final { return &(m_log_file); }
    virtual ofstream* get_output_stream(void) noexcept(true) override final { return &(log_file); }
};

using Observer = _Observer<nullptr>;

extern _Observer<nullptr> observer; // UserClass observer
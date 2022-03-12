#pragma once

#include "User/Base.hpp"

#include <iostream>

using std::cout;

extern mutex m_cout; // mutex for : cout

template <nullptr_t N>
class _Host final : public virtual _UserClass<N>
{
public:
    virtual mutex *get_output_mutex(void) noexcept(true) override final { return &(m_cout); }
    virtual ostream *get_output_stream(void) noexcept(true) override final { return &(cout); }
};

using Host = _Host<nullptr>;

extern _Host<nullptr> host; // UserClass host
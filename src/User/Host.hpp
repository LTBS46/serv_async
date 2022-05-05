#pragma once

#include "User/Base.hpp"

#include <iostream>

using std::cout;
using std::getline;
using std::cin;

extern mutex m_cout; // mutex for : cout

template <nullptr_t N>
class _Host final : public virtual _UserClass<N> {
    public:
    virtual mutex* get_output_mutex(void) noexcept(true) override final { return &(m_cout); }
    virtual ostream* get_output_stream(void) noexcept(true) override final { return &(cout); }
    constexpr virtual bool request_input(string* val, const string& msg = "") override final {
        {scoped_lock<mutex> lk(m_cout); cout << msg; }
        return (bool) getline(cin, *val);
    }
};

using Host = _Host<nullptr>;

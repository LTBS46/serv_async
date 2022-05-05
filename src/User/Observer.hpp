#pragma once

#include <fstream>
#include <mutex>

template <nullptr_t N>
class _Observer;

#include "User/Base.hpp"

using std::mutex;
using std::ofstream;
using std::endl;


template <nullptr_t N>
class _Observer final : public virtual _UserClass<N> {
    public:
    using UserRef = _UserClass<N>*;
    using UserType = _UserClass<N>;
    using SessionRef = UserType::SessionRef;

    protected:
    ofstream log_file; // file to put the server log
    mutex m_log_file;  // mutex for : log_file
    public:

    _Observer(SessionRef r) noexcept : log_file("session/" + r->get_name() + "/log.txt", std::ios_base::app) {
        r->connect(this);
        connect(r);
    }

    virtual mutex* get_output_mutex(void) noexcept(true) override final { return &(m_log_file); }
    virtual ofstream* get_output_stream(void) noexcept(true) override final { return &(log_file); }
    constexpr virtual bool request_input(string* val, const string& msg = "") override final {
        {scoped_lock<mutex> lk(m_log_file); log_file << "wrongful input request to the observer : \"" << msg << "\"" << endl; }
        (*val) = "";
        return false;
    }
};

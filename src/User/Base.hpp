#pragma once

#include <ostream>
#include <mutex>
#include <string>

template <nullptr_t N>
class _UserClass;

#include "Object.hpp"
#include "Session/Base.hpp"

using std::mutex;
using std::ostream;
using std::string;

template <nullptr_t N>
class _UserClass : public virtual _Object<N> {
    public:
    using SessionRef = _Session<N>*;

    protected:
    SessionRef curr_s;

    public:

    constexpr _UserClass(void) noexcept(true) : curr_s(N) { }

    constexpr _UserClass(const _UserClass&) noexcept(true) = delete;
    constexpr _UserClass(_UserClass&&) noexcept(true) = delete;
    virtual _UserClass& operator=(const _UserClass&) noexcept(true) final = delete;
    virtual _UserClass& operator=(_UserClass&&) noexcept(true) final = delete;

    virtual void disconnect(void) noexcept final { if (is_connected()) { connect(N)->disconnect(this); } }
    [[nodiscard]] constexpr virtual SessionRef connect(SessionRef s) final { SessionRef  rv = curr_s; curr_s = s; return rv; }
    [[nodiscard]] constexpr virtual bool is_connected_to(SessionRef s) final { return s == curr_s; }
    [[nodiscard]] constexpr virtual bool is_connected(void) final { return !is_connected_to(N); }
    constexpr virtual void write_ouput(string& s) { scoped_lock<mutex> lk(*get_output_mutex()); *get_output_stream() << s; }
    constexpr virtual bool request_input(string*, const string& msg = "") = 0;
    constexpr virtual string request_input(const string& msg = "") final { string rv; return request_input(&rv, msg) ? rv : ""; }

    virtual mutex* get_output_mutex(void) noexcept(true) = 0;
    virtual ostream* get_output_stream(void) noexcept(true) = 0;
};

using UserClass = _UserClass <nullptr>;
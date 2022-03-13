#pragma once

#include <ostream>
#include <mutex>
#include <string>

#include "Object.hpp"
#include "Session/Base.hpp"

using std::mutex;
using std::ostream;
using std::string;

template <nullptr_t N>
class _UserClass : public virtual _Object<N> {
    protected:
    _Session<N>* current_session;

    public:
    constexpr _UserClass(void) noexcept(true) : current_session(N) { }
    _UserClass(const _UserClass&) noexcept(true) = delete;
    _UserClass(_UserClass&&) noexcept(true) = delete;
    virtual _UserClass& operator=(const _UserClass&) noexcept(true) = delete;
    virtual _UserClass& operator=(_UserClass&&) noexcept(true) = delete;
    virtual ~_UserClass(void) noexcept(true) { }
    virtual mutex* get_output_mutex(void) noexcept(true) = 0;
    virtual ostream* get_output_stream(void) noexcept(true) = 0;
};

using UserClass = _UserClass<nullptr>;

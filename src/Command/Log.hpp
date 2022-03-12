#pragma once

#include <string>

#include "Command/Base.hpp"

using std::endl;
using std::scoped_lock;
using std::string;

template <nullptr_t N>
class _LogCommand : public virtual _Command<N>
{
protected:
    string s;
    UserClass *output;

public:
    _LogCommand(_UserClass<N> *ptr, const string &__s,
                _UserClass<N> *__o) noexcept(true)
        : _Command<N>(ptr), s(__s), output(__o) {}
    virtual void operator()(void) noexcept(true) final override
    {
        scoped_lock lk(*(output->get_output_mutex()));
        *output->get_output_stream() << s << endl;
    }
};

using LogCommand = _LogCommand<nullptr>;
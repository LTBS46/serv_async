#pragma once

#include "Command/Log.hpp"

template <nullptr_t N>
class _EchoCommand : public virtual _LogCommand<N>, public virtual _Command<N>, public virtual Callable<void, true, false, void>, public virtual _Object<N> {
    public:
    _EchoCommand(_UserClass<N>* ptr, const string& s) noexcept(true)
        : _Command<N>(ptr), _LogCommand<N>(ptr, s, ptr) { }
};

using EchoCommand = _EchoCommand<nullptr>;
#pragma once

#include <exception>

#include "Command/Log.hpp"

using std::exception;

template <nullptr_t N>
class _ErrorCommand : public virtual _LogCommand<N>, public virtual _Command<N>, public virtual Callable<void, true, false, void>, public virtual _Object<N> {
    public:
    _ErrorCommand(_UserClass<N>* u, const exception& e) noexcept(true) : _Command<N>(u), _LogCommand<N>(u, e.what(), u) { }
};

using ErrorCommand = _ErrorCommand<nullptr>;
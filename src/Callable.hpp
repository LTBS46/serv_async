#pragma once

#include "Object.hpp"

template <class, bool, bool, class...>
class Callable;

template <typename R, bool ne, typename... Args>
class Callable<R, ne, true, Args...> : public virtual Object
{
public:
    virtual R operator()(Args...) const noexcept(ne) = 0;
};

template <class R, bool ne>
class Callable<R, ne, true, void> : public virtual Object
{
public:
    virtual R operator()(void) const noexcept(ne) = 0;
};

template <class R, bool ne, class... Args>
class Callable<R, ne, false, Args...> : public virtual Object
{
public:
    virtual R operator()(Args...) noexcept(ne) = 0;
};

template <class R, bool ne>
class Callable<R, ne, false, void> : public virtual Object
{
public:
    virtual R operator()(void) noexcept(ne) = 0;
};
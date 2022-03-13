#pragma once

template <decltype(nullptr)>
class _Object {
    public:
    constexpr _Object(void) noexcept = default;
    constexpr virtual ~_Object(void) noexcept = default;
};

using Object = _Object<nullptr>;
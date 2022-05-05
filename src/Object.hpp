#pragma once

template<decltype(nullptr)>
class _Object {
    public:
    constexpr _Object(void) noexcept { };
    constexpr virtual ~_Object(void) noexcept { };

};

#pragma once

#include "Command/Base.hpp"

void push_command(Command*) noexcept(true);
[[nodiscard]] Command* pop_command(void) noexcept(true);
#pragma once

#include "Command/Base.hpp"
#include "User/Base.hpp"

[[nodiscard]] Command *parse_command(UserClass *, string) noexcept(true);
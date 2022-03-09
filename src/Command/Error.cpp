#include "Command/Error.hpp"

ErrorCommand::ErrorCommand(UserClass *u, const exception &e) noexcept(true) : Command(u), LogCommand(u, e.what(), u) {}
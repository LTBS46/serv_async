#include "Command/Exit.hpp"

atomic_bool exit_trigger = false;
atomic_int exit_code = 0;
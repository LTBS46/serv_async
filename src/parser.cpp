#include <stdexcept>

#include "parser.hpp"
#include "regex.hpp"
#include "Command/Exit.hpp"
#include "User/Host.hpp"
#include "Command/Error.hpp"
#include "Command/Echo.hpp"

using std::out_of_range;
using std::smatch;

[[nodiscard]] ExitCommand* make_exit_cmd(UserClass* ptr, int rv) noexcept(true) {
    return new ExitCommand(ptr, rv);
}

[[nodiscard]] Command* make_exit_cmd(UserClass* ptr, string str) noexcept(true)
try {
    return make_exit_cmd(ptr, stoi(str));
} catch (const out_of_range& oor) {
    return new ErrorCommand(ptr, oor);
}

[[nodiscard]] Command* parse_command(UserClass* ptr, string s) noexcept(true)
try {
    smatch match_obj;
    if (regex_match(s, match_obj, exit_regex))
        return new ExitCommand(ptr);
    else if (regex_match(s, match_obj, qual_exit_regex))
        return make_exit_cmd(ptr, match_obj[1]);
    else
        return nullptr;
} catch (const exception& e) {
    return new ErrorCommand(ptr, e);
}
#include <stdexcept>

#include "parser.hpp"
#include "regex.hpp"
#include "Command/Exit.hpp"
#include "User/Host.hpp"
#include "Command/GetAdminLevel.hpp"
#include "Command/Error.hpp"

using std::out_of_range;
using std::smatch;

[[nodiscard]] ExitCommand *make_exit_cmd(UserClass *ptr, int rv) noexcept(true)
{
    return new ExitCommand(ptr, rv);
}

[[nodiscard]] Command *make_exit_cmd(UserClass *ptr, string str) noexcept(true)
try
{
    return make_exit_cmd(ptr, stoi(str));
}
catch (const out_of_range &oor)
{
    return new ErrorCommand(ptr, oor);
}

[[nodiscard]] Command *parse_command_get(smatch &match_obj, UserClass *ptr) noexcept(true)
{
    UserClass *target = (match_obj[1] == "self") ? ptr
                        : (match_obj[1] == "host")
                            ? (UserClass *)&host
                        : (match_obj[1] == "observer")
                            ? (UserClass *)&observer
                            : nullptr;
    if (target == nullptr)
        return nullptr;
    return (match_obj[2] == "admin") ? new GetAdminLevelCommand(ptr, target)
                                     : nullptr;
}

[[nodiscard]] Command *parse_command(UserClass *ptr, string s) noexcept(true)
try
{
    smatch match_obj;
    return (regex_match(s, match_obj, exit_regex)) ? new ExitCommand(ptr)
           : (regex_match(s, match_obj, qual_exit_regex))
               ? make_exit_cmd(ptr, match_obj[1])
           : (regex_match(s, match_obj, echo_regex))
               ? new EchoCommand(ptr, match_obj[1])
           : (regex_match(s, match_obj, get_regex))
               ? parse_command_get(match_obj, ptr)
               : nullptr;
}
catch (const exception &e)
{
    return new ErrorCommand(ptr, e);
}
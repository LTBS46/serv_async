#include <iostream>

#include "host_io.hpp"
#include "User/Host.hpp"
#include "queue.hpp"
#include "Command/Exit.hpp"
#include "parser.hpp"

using std::cin;

void default_io_commands_getter(void) noexcept(true)
{
    string line;
    while (getline(cin, line))
    {
        Command *c;
        push_command(c = parse_command(&(host), line));
        if (c->is_exit())
            return;
    }
    push_command(new ExitCommand(&host));
}
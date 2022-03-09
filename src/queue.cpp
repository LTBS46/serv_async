#include <mutex>
#include <queue>

#include "queue.hpp"

using std::queue;
using std::scoped_lock;

using CommandQueue = queue<Command *>;

CommandQueue cmd_queue;

mutex m_cmd_queue;

void push_command(Command *ptr) noexcept(true)
{
    scoped_lock<mutex> lk(m_cmd_queue);
    cmd_queue.push(ptr);
}

[[nodiscard]] Command *pop_command(void) noexcept(true)
{
    scoped_lock<mutex> lk(m_cmd_queue);
    if (not cmd_queue.empty())
    {
        Command *c = cmd_queue.front();
        cmd_queue.pop();
        return c;
    }
    else
        return nullptr;
}
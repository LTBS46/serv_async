#include <ostream>
#include <mutex>
#include <memory>

#include "Command/Base.hpp"

using std::addressof;
using std::endl;
using std::scoped_lock;

Command::Command(UserClass *ptr) noexcept(true)
    : usr(ptr not_eq nullptr ? ptr : addressof(observer)) {}

Command::~Command(void) noexcept(true) {}

bool Command::is_exit(void) const volatile noexcept(true) { return false; }

#pragma once

#include <set>
#include <unordered_set>
#include <queue>
#include <mutex>

template <nullptr_t N>
class _Session;

#include "User/Observer.hpp"
#include "Command/Base.hpp"

using std::set;
using std::unordered_set;
using std::mutex;
using std::string;
using std::queue;
using std::scoped_lock;
using std::ofstream;

template <nullptr_t N>
class _Session : public virtual _Object<N> {
    public:
    using UserRef = _UserClass<N>*;
    using CommandRef = _Command<N>*;
    using CommandQueue = queue<CommandRef>;
    using UsersList = unordered_set<UserRef>;
    using Bystander = _Observer<N>;

    protected:
    string name;
    CommandQueue cmd_queue;
    UsersList users;
    Bystander observer;
    mutex m_cmd_queue, m_users;

    _Session(const string& s) noexcept : name(s) { enable_observer(); }
    _Session(string&& s) noexcept : name(s) { enable_observer(); }

    public:

    virtual ~_Session(void) noexcept { ofstream(); }

    constexpr _Session(const _Session&) noexcept = delete;
    constexpr _Session(_Session&&) noexcept = delete;
    constexpr virtual _Session& operator=(_Session&&) noexcept final = delete;
    constexpr virtual _Session& operator=(const _Session&) noexcept final = delete;

    virtual const string& get_name(void) const noexcept final { return name; }

    virtual void connect(UserRef u) noexcept { if (not users.contains(u)) users.insert(u); }
    virtual void disconnect(UserRef u) noexcept { if (users.contains(u)) users.erase(u); }
    [[nodiscard]] virtual bool observer_enabled(void) const noexcept final { return users.contains(&observer); }
    virtual void set_observer(bool b) noexcept final { if (observer_enabled() xor b) { if (b) connect(&observer); else disconnect(&observer); } }
    virtual void enable_observer(void) noexcept final { set_observer(true); }
    virtual void disable_observer(void) noexcept final { set_observer(false); }
    virtual void toggle_observer(void) noexcept final { set_observer(not observer_enabled()); }

    virtual void push_command(CommandRef ptr) noexcept(true) final {
        scoped_lock<mutex> lk(m_cmd_queue);
        cmd_queue.push(ptr);
    }

    [[nodiscard]] virtual CommandRef pop_command(void) noexcept(true) final {
        scoped_lock<mutex> lk(m_cmd_queue);
        CommandRef c = (not cmd_queue.empty()) ? cmd_queue.front() : nullptr;
        cmd_queue.pop();
        return c;
    }
};
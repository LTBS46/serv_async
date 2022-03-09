#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <fstream>
#include <exception>
#include <vector>

#include "queue.hpp"
#include "host_io.hpp"
#include "Command/Exit.hpp"

using std::cerr;
using std::cin;
using std::endl;
using std::exception;
using std::ios_base;
using std::scoped_lock;
using std::string;
using std::thread;
using std::vector;

ofstream log_file;

thread t_default_io;

mutex m_cout;
mutex m_cerr;
mutex m_exit_trigger;
mutex m_log_file;

//
//

void cleanup(void) noexcept(true)
{
  t_default_io.join();
  Command *c;
  while ((c = pop_command()) not_eq nullptr)
  {
    (*c)();
    delete c;
  }
}

void main_thread(void) noexcept(true)
{
  Command *c = nullptr;
  while (true)
  {
    {
      scoped_lock lk(m_exit_trigger);
      if (exit_trigger)
        break;
    }
    if ((c = pop_command()) not_eq nullptr)
    {
      (*c)();
      delete c;
    }
  }
  exit(exit_code);
}

void set_env(vector<string> &vs) noexcept(true)
try
{
  for (const string &s : vs)
  {
  }
}
catch (const exception &e)
{
}

void set_env(int argc, const char *const *argv) noexcept(true)
try
{
  vector<string> tmp;
  for (int i = 0; i < argc; i++)
    tmp.push_back(argv[i]);
}
catch (const exception &e)
{
}

//
//

int main(int argc, char **argv)
try
{
  int tmp = atexit(cleanup);
  if (not tmp)
  {
    log_file = ofstream(string("log.txt"), ios_base::app);
    set_env(argc, argv);
    t_default_io = thread(default_io_commands_getter);
    main_thread();
  }
  else
  {
    scoped_lock lk(m_cerr);
    cerr << "atexit() failure : returned " << tmp << endl;
  }
  return -1;
}
catch (exception &e)
{
  scoped_lock lk(m_cerr);
  cerr << "error : " << e.what() << endl;
  return -1;
}
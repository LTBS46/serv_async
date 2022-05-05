#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <fstream>
#include <exception>
#include <vector>

#include "queue.hpp"
#include "parser.hpp"
#include "User/Host.hpp"
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

mutex m_cout;
mutex m_cerr;
mutex m_exit_trigger;
mutex m_log_file;

//
//

void cleanup(void) noexcept(true) { }

//
//

int main(int argc, char** argv)
try {
  int tmp = atexit(cleanup);
  if (not tmp) {
    log_file = ofstream(string("log.txt"), ios_base::app);
    vector<string> args;
    for (int i = 0; i < argc; i++)
      args.push_back(argv[i]);
    string line;_Host<nullptr> host;
    while (getline(cin, line)) {
      Command* c;
      c = parse_command(&(host), line);
      (*c)();
      bool is_exit = c->has_trait(CommandFlags::Exit);
      delete c;
      if (is_exit)
        return exit_code;
    }
    (ExitCommand(&host))();
    return exit_code;
  } else {
    scoped_lock lk(m_cerr);
    cerr << "atexit() failure : returned " << tmp << endl;
  }
  return -1;
} catch (exception& e) {
  scoped_lock lk(m_cerr);
  cerr << "error : " << e.what() << endl;
  return -1;
}
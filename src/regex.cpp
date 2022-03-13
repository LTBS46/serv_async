#include "regex.hpp"

using namespace std::regex_constants;

const regex exit_regex = regex("^exit$", ECMAScript bitor icase bitor optimize);

const regex qual_exit_regex =
regex("^exit (\\d+)$", ECMAScript bitor icase bitor optimize);

const regex connect_session_regex = regex("^connect (\\S+)$", ECMAScript bitor icase bitor optimize);
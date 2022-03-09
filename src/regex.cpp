#include "regex.hpp"

using namespace std::regex_constants;

const regex exit_regex = regex("^exit$", ECMAScript bitor icase bitor optimize);

const regex qual_exit_regex =
    regex("^exit (\\d*)$", ECMAScript bitor icase bitor optimize);

const regex echo_regex = regex("^echo (.*)$", ECMAScript bitor icase bitor optimize);

const regex get_regex =
    regex("^get (\\w*) (\\w*)$", ECMAScript bitor icase bitor optimize);
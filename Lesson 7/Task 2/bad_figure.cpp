#include "bad_figure.h"

bad_figure::bad_figure(const char* msg) : std::domain_error(msg) {};
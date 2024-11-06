#pragma once

#include <iostream>

struct bad_figure : public std::domain_error {
	bad_figure(const char*);
};
#pragma once

#include <string>

#ifdef leaver_library_EXPORTS
#define LEAVERLIBRARY_API __declspec(dllexport)
#else
#define LEAVERLIBRARY_API __declspec(dllimport)
#endif

class Leaver {
	public:
		LEAVERLIBRARY_API std::string leave(std::string);
};
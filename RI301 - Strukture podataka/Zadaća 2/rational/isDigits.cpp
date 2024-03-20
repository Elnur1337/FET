#include "isDigits.h"
bool isDigits(const std::string& str)
{
	return std::all_of(str.begin(), str.end(), ::isdigit);
}
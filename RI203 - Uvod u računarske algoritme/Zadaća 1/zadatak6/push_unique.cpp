#include "push_unique.h"

bool push_unique(std::vector<int>& v, int e) {
	std::vector<int>::iterator it = std::find_if(v.begin(), v.end(), [e](int v) {
		return e == v;
		}
	);
	if (it != v.end()) {
		return false;
	}
	v.push_back(e);
	return true;
}
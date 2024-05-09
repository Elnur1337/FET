#pragma once

template <typename Iter, typename P>
Iter stable_partition(Iter begin, Iter end, const P& p) {
	Iter secondBegin{ begin++ };
	while (begin != end) {
		if (p(*begin) && !p(*secondBegin)) {
			Iter temp{ begin };
			while (!p(*(temp - 1))) {
				std::swap(*temp, *(temp - 1));
				--temp;
			}
			++secondBegin;
		}
		if (p(*secondBegin)) {
			++secondBegin;
		}
		if (!p(*begin)) {
			++begin;
		}
	}
	return secondBegin;
}
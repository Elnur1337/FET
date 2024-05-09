#pragma once

template <typename It, typename T>
It upper_bound(It begin, It end, const T& element) {
	while (begin < end) {
		It mid = begin + (end - begin) / 2;
		if (*mid == element || mid == begin || (*(mid - 1) < element && *mid > element)) {
			return mid;
		}
		if (*mid <= element) {
			begin = mid + 1;
		}
		else {
			end = mid;
		}
	}
	return begin;
}
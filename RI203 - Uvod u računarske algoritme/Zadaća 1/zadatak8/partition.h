#pragma once
#include <algorithm>

template <typename Iter, typename P>
Iter partition(Iter begin, Iter end, const P& p) {
    Iter secondBegin{ begin++ };
    while (begin != end) {
        if (p(*begin) && !p(*secondBegin)) {
            std::swap(*begin, *secondBegin);
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
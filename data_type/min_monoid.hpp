#ifndef MIN_MONOID_HPP
#define MIN_MONOID_HPP

#include <algorithm>
#include <limits>
#include <numeric>

//===
template <class T>
struct MinMonoid {
    using value_type = T;
    inline static T identity() {
        return std::numeric_limits<T>::max();
    };
    inline static T operation(const T a, const T b) {
        return std::min(a, b);
    };
};
//===

#endif

#ifndef SUM_MONOID_HPP
#define SUM_MONOID_HPP

template<class T>
struct SumMonoid {
    using value_type = T;
    inline static identity() {
        return 0;
    };
    inline static operation(const T a, const T b) {
        return a + b;
    };
};

#endif

#ifndef SUM_MONOID_HPP
#define SUM_MONOID_HPP

template<class T>
struct SumMonoid {
    using value_type = T;
    inline static T identity() {
        return (T)0;
    };
    inline static T operation(const T a, const T b) {
        return a + b;
    };
};

#endif

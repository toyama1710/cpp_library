#ifndef MAKE_VECTOR_HPP
#define MAKE_VECTOR_HPP

#include <cassert>
#include <initializer_list>
#include <vector>

template <class T, uint64_t N>
auto make_vector_(const uint64_t *dim, T e) {
    if constexpr (N == 1) {
        return std::vector<T>(*dim, e);
    } else {
        auto v = make_vector_<T, N - 1>(dim + 1, e);
        return std::vector<decltype(v)>(*dim, v);
    }
};
template <class T, uint64_t N>
auto make_vector(const uint64_t (&dim)[N], const T &e) {
    assert(N > 0);
    return make_vector_<T, N>(dim, e);
};

#endif
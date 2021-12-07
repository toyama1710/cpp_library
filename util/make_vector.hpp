#ifndef MAKE_VECTOR_HPP
#define MAKE_VECTOR_HPP

#include <cassert>
#include <initializer_list>
#include <vector>

template <class T, std::size_t N>
auto make_vector_(const std::size_t *dim, T e) {
    if constexpr (N == 1) {
        return std::vector<T>(*dim, e);
    } else {
        auto v = make_vector_<T, N - 1>(dim + 1, e);
        return std::vector<decltype(v)>(*dim, v);
    }
};
template <class T, std::size_t N>
auto make_vector(const std::size_t (&dim)[N], const T &e) {
    assert(N > 0);
    return make_vector_<T, N>(dim, e);
};

    /*
    template <class... Args>
    auto make_vector(std::size_t k, Args... args) {
        auto v = make_vector(k, make_vector(args...));
        return std::vector<decltype(v)>(k, v);
    };

    template <class T>
    std::vector<T> make_vector(std::size_t k, T x) {
        return std::vector<T>(k, x);
    };
    */

#endif
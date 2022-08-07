#ifndef COORDINATE_COMPRESSION_HPP
#define COORDINATE_COMPRESSION_HPP
#include <algorithm>
#include <vector>

template <class T>
struct CoordinateCompression {
    std::vector<T> p;

    template <class InputItr>
    CoordinateCompression(InputItr first, InputItr last) : p(first, last) {
        std::sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());
    };
    int zip(T x) {
        return std::lower_bound(p.begin(), p.end(), x) - p.begin();
    };
    T unzip(int x) {
        return p[x];
    };
    int size() {
        return p.size();
    };
};

template <class T>
struct CoordinateCompressionBuilder {
    std::vector<T> p;

    CoordinateCompressionBuilder() = default;
    template <class InputItr>
    CoordinateCompressionBuilder(InputItr first, InputItr last)
        : p(first, last){};
    void push(T x) {
        p.push_back(x);
    };
    CoordinateCompression<T> build() {
        return CoordinateCompression<T>(p.begin(), p.end());
    };
};

#endif

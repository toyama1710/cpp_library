#ifndef COORDINATE_COMPRESSION_HPP
#define COORDINATE_COMPRESSION_HPP
// header file section
#include <vector>
#include <iterator>
#include <algorithm>
#include <cassert>

//===
// library section
// <iterator>
struct CoordinateCompression {
    using llong = long long;
    std::vector<llong> p;

#ifndef NDEBUG
    bool builded = false;
#endif

    CoordinateCompression () {};
    template <class InputItr>
    CoordinateCompression (InputItr first, InputItr last) {
        p.reserve(std::distance(first, last));
        for (auto itr = first; itr != last; itr++) {
            p.push_back(*itr);
        }
        build();
    };

    void build() {
        std::sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());
#ifndef NDEBUG
        builded = true;
#endif
    };

    void add(llong a) {
        p.push_back(a);
#ifndef NDEBUG
        builded = false;
#endif
    };
    void push(llong a) {
        add(a);
    }

    llong zip(llong x) {
#ifndef NDEBUG
        assert(builded);
#endif
        return std::lower_bound(p.begin(), p.end(), x) - p.begin();
    };
    llong unzip(llong x) {
#ifndef NDEBUG
        assert(builded);
#endif
        return p[x];
    };

    llong size() {
        return p.size();
    };
};
//===
#endif

// header file section
#include <iostream>
#include <cstdio>
#include <cfloat>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <algorithm>
#include <iterator>

using namespace std;
using llong = long long;

//===
// library section
// <iterator>
struct CoordinateCompression {
    vector<llong> p;

    CoordinateCompression () {};
    template <class InputItr>
    CoordinateCompression (InputItr first, InputItr last) {
        p.reserve(distance(first, last));
        for (auto itr = first; itr != last; itr++) {
            p.push_back(*itr);
        }
        build();
    };

    void build() {
        sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());
    };

    void add(llong a) {
        p.push_back(a);
    };

    llong zip(llong x) {
        return lower_bound(p.begin(), p.end(), x) - p.begin();
    };
    llong unzip(llong x) {
        return p[x];
    };

    llong size() {
        return p.size();
    };
};
//===

int main() {
    return 0;
};


#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

// header file section
#include <algorithm>
#include <bitset>
#include <cfloat>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include "../../union_find/weighted_union_find.hpp"

using namespace std;
using llong = long long;

struct A {
    using T = llong;
    using value_type = T;

    static inline T identity() {
        return 0;
    };

    static inline T operation(T x, T y) {
        return x + y;
    };

    static inline T inverse(T x) {
        return -x;
    };
};

llong n, q;
llong com, x, y, w;

int main() {
    cin >> n >> q;
    WeightedUnionFind<A> uf(n);

    while (q--) {
        cin >> com;

        if (com == 0) {
            cin >> x >> y >> w;
            uf.unite(x, y, w);
        } else {
            cin >> x >> y;

            if (uf.same(x, y)) {
                cout << uf.diff(x, y) << '\n';
            } else {
                cout << "?\n";
            }
        }
    }

    return 0;
};

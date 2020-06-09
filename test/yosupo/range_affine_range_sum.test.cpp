#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include <iostream>
#include <utility>
#include "../../segment_tree/lazy_segment_tree.hpp"
using llong = long long;
using namespace std;

struct A {
    struct M {
        using value_type = pair<llong, llong>;
        inline static value_type identity() {
            return {0, 0};
        };
        inline static value_type operation(value_type a, value_type b) {
            return {(a.first + b.first) % 998244353, a.second + b.second};
        };
    };
    struct O {
        using value_type = pair<llong, llong>;
        inline static value_type identity() {
            return {1ll, 0ll};
        };
        inline static value_type operation(value_type x, value_type y) {
            auto ret = identity();
            ret.first = (x.first * y.first) % 998244353;
            ret.second = (y.first * x.second + y.second) % 998244353;
            return ret;
        };
    };
    using value_structure = M;
    using operator_structure = O;
    inline static M::value_type operation(M::value_type a, O::value_type b) {
        return {(b.first * a.first + b.second * a.second) % 998244353, a.second};
    };
};

llong n, q;
llong a;
llong com, s, t, b, c;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> q;
    LazySegmentTree<A> seg(n);
    for (int i = 0; i < n; i++) {
        cin >> a;
        seg.set(i, {a, 1});
    }

    while (q--) {
        cin >> com;

        if (com == 0) {
            cin >> s >> t >> b >> c;
            seg.update(s, t, {b, c});
        }
        else {
            cin >> s >> t;
            cout << seg.fold(s, t).first << '\n';
        }
    }
}
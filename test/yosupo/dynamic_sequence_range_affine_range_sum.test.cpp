#define IGNORE
#define PROBLEM \
    "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"
#include <iostream>
#include <valarray>

#include "../../bbst/avl_array.hpp"

#define _overload(_1, _2, _3, _4, name, ...) name
#define _rep1(Itr, N) _rep3(Itr, 0, N, 1)
#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)
#define _rep3(Itr, a, b, step) for (i64 Itr = a; Itr < b; Itr += step)
#define repeat(...) _overload(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)
#define rep(...) repeat(__VA_ARGS__)

#define ALL(X) begin(X), end(X)

using namespace std;
using i64 = long long;
using u64 = unsigned long long;

constexpr i64 mod = 998244353;
struct A {
    struct M {
        using T = pair<int, int>;
        using value_type = T;
        static T identity() { return {0, 0}; };
        static T operation(T lhs, T rhs) {
            return {(lhs.first + rhs.first) % mod, lhs.second + rhs.second};
        };
    };
    struct O {
        using T = pair<int, int>;
        using value_type = T;
        static T identity() { return {1, 0}; };
        static T operation(T lhs, T rhs) {
            return {((i64)lhs.first * rhs.first) % mod,
                    ((i64)lhs.second * rhs.first + rhs.second) % mod};
        };
    };

    using value_structure = M;
    using operator_structure = O;
    static M::T operation(M::T v, O::T o) {
        return {((i64)v.first * o.first + (i64)v.second * o.second) % mod,
                v.second};
    };
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    AVLArray<A> arr;

    i64 n, q;
    cin >> n >> q;
    rep(i, n) {
        i64 a;
        cin >> a;
        arr.insert_at(i, {a, 1});
    }

    i64 com, i, l, r, a, b, c;
    rep(_, q) {
        cin >> com;

        switch (com) {
            case 0: {
                cin >> i >> a;
                arr.insert_at(i, {a, 1});
                break;
            }
            case 1: {
                cin >> i;
                arr.erase_at(i);
                break;
            }
            case 2: {
                cin >> l >> r;
                arr.reverse(l, r);
                break;
            }
            case 3: {
                cin >> l >> r >> b >> c;
                arr.update(l, r, {b, c});
                break;
            }
            case 4: {
                cin >> l >> r;
                cout << arr.fold(l, r).first << '\n';
                break;
            }
        }
    }

    return 0;
}
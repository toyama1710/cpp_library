#define PROBLEM \
    "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"
#include <iostream>

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
        static T identity() {
            return {0, 0};
        };
        static T operation(T lhs, T rhs) {
            return {(lhs.first + rhs.first) % mod, lhs.second + rhs.second};
        };
    };
    struct O {
        using T = pair<int, int>;
        using value_type = T;
        static T identity() {
            return {1, 0};
        };
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
    AVLArray<A> arr;

    int n, q;
    scanf("%d %d", &n, &q);
    rep(i, n) {
        int a;
        scanf("%d", &a);
        arr.insert_at(i, {a, 1});
    }

    int com, i, l, r, a, b, c;
    rep(_, q) {
        scanf("%d", &com);

        switch (com) {
            case 0: {
                scanf("%d %d", &i, &a);
                arr.insert_at(i, {a, 1});
                break;
            }
            case 1: {
                scanf("%d", &i);
                arr.erase_at(i);
                break;
            }
            case 2: {
                scanf("%d %d", &l, &r);
                arr.reverse(l, r);
                break;
            }
            case 3: {
                scanf("%d %d %d %d", &l, &r, &b, &c);
                arr.update(l, r, {b, c});
                break;
            }
            case 4: {
                scanf("%d %d", &l, &r);
                printf("%d\n", arr.fold(l, r).first);
                break;
            }
        }
    }

    return 0;
}

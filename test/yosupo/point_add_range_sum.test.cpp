#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

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

struct Sum {
    struct M {
        using T = pair<i64, i64>;
        using value_type = T;
        static T identity() {
            return {0, 0};
        };
        static T operation(T lhs, T rhs) {
            return {lhs.first + rhs.first, lhs.second + rhs.second};
        };
    };
    struct O {
        using T = i64;
        using value_type = T;
        static T identity() {
            return 0;
        };
        static T operation(T lhs, T rhs) {
            return lhs + rhs;
        };
    };

    using value_structure = M;
    using operator_structure = O;
    static M::T operation(M::T v, O::T o) {
        return {v.first + o * v.second, v.second};
    };
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    AVLArray<Sum> arr;
    rep(i, n) {
        i64 a;
        cin >> a;
        arr.insert_at(i, {a, 1});
    }

    i64 com, a, b;
    rep(_, q) {
        cin >> com >> a >> b;
        if (com == 0) {
            if (_ & 1)
                arr.update(a, a + 1, b);
            else
                arr.set(a, {arr[a].first + b, 1});
        } else if (com == 1) {
            cout << arr.fold(a, b).first << '\n';
        }
    }

    return 0;
}
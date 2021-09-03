#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"
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
constexpr i64 inf = 1ll << 60;

struct A {
    struct M {
        using T = i64;
        using value_type = T;
        static T identity() { return inf; };
        static T operation(T lhs, T rhs) { return min(lhs, rhs); };
    };
    struct O {
        using T = int;
        using value_type = T;
        static T identity() { return 0; };
        static T operation(T lhs, T rhs) { return 0; };
    };

    using value_structure = M;
    using operator_structure = O;
    static M::T operation(M::T v, O::T o) { return v; };
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    i64 n, q;
    cin >> n >> q;
    AVLArray<A> arr;

    rep(_, n) {
        i64 a;
        cin >> a;
        AVLArray<A> tmp;
        tmp.insert_at(0, a);
        arr.append(tmp);
    }

    i64 x, y, z;
    rep(_, q) {
        cin >> x >> y >> z;
        switch (x) {
            case 0: {
                arr.rotate(y, z, z + 1);
                break;
            }
            case 1: {
                cout << arr.fold(y, z + 1) << '\n';
                break;
            }
            case 2: {
                arr.erase_at(y);
                arr.insert_at(y, z);
                break;
            }
        }
    }

    return 0;
}
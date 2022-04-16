#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1418"

#include <algorithm>
#include <array>
#include <iostream>
#include <set>

#include "../../math/prime_factorize_table.hpp"
#include "../../segment_tree/dynamic_segment_tree.hpp"

#define _overload(_1, _2, _3, _4, name, ...) name
#define _rep1(Itr, N) _rep3(Itr, 0, N, 1)
#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)
#define _rep3(Itr, a, b, step) for (i64 Itr = a; Itr < b; Itr += step)
#define repeat(...) _overload(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)
#define rep(...) repeat(__VA_ARGS__)

#define ALL(X) begin(X), end(X)

using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using u8 = unsigned char;

struct M {
    using T = array<int, 4>;
    using value_type = T;
    const static u8 inf = 100;
    static T identity() { return {inf, inf, inf, 0}; };
    static T operation(T lhs, T rhs) {
        T ret;
        int li = 0, ri = 0;
        rep(i, 3) {
            if (lhs[li] < rhs[ri]) {
                ret[i] = lhs[li];
                li++;
            } else {
                ret[i] = rhs[ri];
                ri++;
            }
        }
        ret[3] = lhs[3] + rhs[3];
        return ret;
    };
};

struct SUM {
    using T = int;
    using value_type = T;
    static T identity() { return 0; };
    static T operation(T lhs, T rhs) { return lhs + rhs; };
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    i64 n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &vs : a) cin >> vs;

    vector<DynamicSegmentTree<M>> seg(1'000'000 + 1);

    PrimeFactorizeTable fact(1'000'000 + 1);

    rep(i, n) {
        if (a[i] > 1) {
            for (auto e : fact.factorize(a[i])) {
                auto [p, cnt] = e;
                seg[p].update(i, {u8(cnt), M::inf, M::inf, 1});
            }
        }
    }

    auto power = [&](i64 a, i64 b) {
        i64 ret = 1;
        while (b) {
            if (b & 1) {
                ret *= a;
            }
            a *= a;
            b >>= 1;
        }
        return ret;
    };
    auto enumerate = [&](i64 l, i64 k) {
        set<int> st;
        rep(i, l, l + k + 1) {
            if (a[i] > 1) {
                for (auto e : fact.factorize(a[i])) {
                    st.insert(e.first);
                }
            }
        }
        return st;
    };
    rep(_, q) {
        char c;
        cin >> c;

        if (c == 'U') {
            i64 i, x;
            cin >> i >> x;
            --i;
            if (a[i] > 1) {
                for (auto e : fact.factorize(a[i])) {
                    auto [p, cnt] = e;
                    seg[p].update(i, M::identity());
                }
            }
            if (x > 1) {
                for (auto e : fact.factorize(x)) {
                    auto [p, cnt] = e;
                    seg[p].update(i, {u8(cnt), M::inf, M::inf, 1});
                }
            }
            a[i] = x;
        } else {
            i64 l, r, k;
            cin >> l >> r >> k;
            --l;
            i64 ans = 1;
            for (auto p : enumerate(l, k)) {
                i64 z = (r - l) - seg[p].fold(l, r)[3];
                i64 x;
                if (z > k)
                    x = 0;
                else
                    x = seg[p].fold(l, r)[k - z];

                if (x == M::inf) x = 0;
                ans *= power(p, x);
            }
            cout << ans << '\n';
        }
    }

    return 0;
}
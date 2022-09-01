#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0646"

#include <bits/stdc++.h>

#include "../../segment_tree/segment_tree.hpp"

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

struct SUM {
    using T = i64;
    using value_type = T;
    static T identity() {
        return 0;
    };
    static T operation(T lhs, T rhs) {
        return lhs + rhs;
    };
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    i64 n, k, l;
    cin >> n >> k >> l;
    vector<i64> a(n);
    for (auto &a : a) cin >> a;

    i64 valid = n;
    i64 invalid = 0;
    while (valid - invalid > 1) {
        i64 mid = (valid + invalid) / 2;

        SegmentTree<SUM> seg(n);
        rep(i, n) {
            seg.update(i, seg[i] + (a[i] <= mid));
        }

        i64 cnt = 0;
        auto f = [&](i64 sum) { return sum >= k; };
        rep(i, n) {
            i64 r = seg.find_first(i, f);
            if (r >= 0) {
                cnt += n - r + 1;
            }
        }

        if (cnt >= l)
            valid = mid;
        else
            invalid = mid;
    }

    cout << valid << endl;

    return 0;
}
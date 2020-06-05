#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include <iostream>
#include "../../sparse_table/disjoint_sparse_table.hpp"
using namespace std;
using llong = long long;

struct Sum {
    using T = llong;
    using value_type = T;

    inline static T operation(T x, T y) {
        return x + y;
    };
};

llong n, q;
vector<llong> a;
DisjointSparseTable<Sum> dst;

int main() {
    cin >> n >> q;
    a.resize(n);
    for (auto &v:a) cin >> v;

    dst.build(a.begin(), a.end());

    while (q--) {
        llong l, r;
        cin >> l >> r;
        cout << dst.fold(l, r) << '\n';
    }
}
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <limits>

#include "../../data_type/min_monoid.hpp"
#include "../../sparse_table/sparse_table.hpp"
using namespace std;
using llong = long long;

llong n, q;
vector<llong> a;

int main() {
    cin >> n >> q;
    a.resize(n);
    for (auto &v : a) cin >> v;

    SparseTable<MinMonoid<llong>> rmq(a.begin(), a.end());

    while (q--) {
        llong l, r;
        cin >> l >> r;
        cout << rmq.fold(l, r) << '\n';
    }

    return 0;
}

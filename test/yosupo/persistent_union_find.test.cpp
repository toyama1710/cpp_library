#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include "../../union_find/persistent_union_find.hpp"

using namespace std;
using llong = long long;
using UF = PersistentUnionFind<32>;

llong n, q;
llong t, k, u, v;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> q;

    vector<UF> uf(q);
    uf[0] = UF(n);

    for (int i = 1; i <= q; i++) {
        cin >> t >> k >> u >> v;
        k++;

        if (t == 0) {
            uf[i] = uf[k].unite(u, v);
        } else if (t == 1) {
            if (uf[k].same(u, v)) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }

    return 0;
}

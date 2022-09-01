#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
// header file section
#include <algorithm>
#include <bitset>
#include <cfloat>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include "../../union_find/union_find.hpp"

using namespace std;
using llong = long long;

llong n, q;
llong com, u, v;
UnionFind uf;

int main() {
    cin >> n >> q;
    uf.init(n);

    while (q--) {
        cin >> com >> u >> v;

        if (com == 0) {
            uf.unite(u, v);
        } else {
            cout << (uf.same(u, v) ? 1 : 0) << endl;
        }
    }

    return 0;
};

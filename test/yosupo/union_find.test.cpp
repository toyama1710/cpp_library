#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
// header file section
#include <iostream>
#include <cstdio>
#include <cfloat>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <algorithm>
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
        }
        else {
            cout << (uf.same(u, v) ? 1 : 0) << endl;
        }
    }

    return 0;
};


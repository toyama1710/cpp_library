#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include "../../array/persistent_array.hpp"
#include "../../disjoint_set/persistent_union_find.hpp"

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
        }
        else if (t == 1) {
            if (uf[k].same(u, v)) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
    }
     
    return 0;
}

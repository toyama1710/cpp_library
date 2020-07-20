#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include "../../cht/li_chao_tree.hpp"

using namespace std;
using llong = long long;

llong n, q;
vector<tuple<llong, llong, llong>> query;
vector<llong> a, b;
vector<llong> p;

int main() {
    cin >> n >> q;
    a.resize(n);
    b.resize(n);
    query.resize(q);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < q; i++) {
        llong com, x, y;

        cin >> com;
        if (com == 0) {
            cin >> x >> y;
        }
        else {
            cin >> x;
            p.push_back(x);
        }
        query[i] = tie(com, x, y);
    }

    sort(p.begin(), p.end());
    LiChaoTree<llong> cht(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
        cht.add_line(a[i], b[i]);
    }

    for (int i = 0; i < q; i++) {
        llong com, x, y;
        tie(com, x, y) = query[i];

        if (com == 0) {
            cht.add_line(x, y);
        }
        else {
            cout << cht.get(x) << endl;
        }
    }

    return 0;
};


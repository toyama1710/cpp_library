#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include "../../cht/li_chao_tree.hpp"

using namespace std;
using llong = long long;

llong n, q;
vector<tuple<llong, llong, llong, llong, llong>> query;
vector<llong> l, r;
vector<llong> a, b;
vector<llong> p;

int main() {
    cin >> n >> q;
    l.resize(n);
    r.resize(n);
    a.resize(n);
    b.resize(n);
    query.resize(q);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i] >> a[i] >> b[i];
        p.push_back(l[i]);
        p.push_back(r[i]);
    }

    for (int i = 0; i < q; i++) {
        llong com, l, r, a, b;

        cin >> com;
        if (com == 0) {
            cin >> l >> r >> a >> b;
            p.push_back(l);
            p.push_back(r);
        }
        else {
            cin >> l;
            p.push_back(l);
        }
        query[i] = tie(com, l, r, a, b);
    }

    LiChaoTree<llong> cht(p);
    for (int i = 0; i < n; i++) {
        cht.add_segment(a[i], b[i], l[i], r[i]);
    }

    for (int i = 0; i < q; i++) {
        llong com, l, r, a, b;
        tie(com, l, r, a, b) = query[i];

        if (com == 0) {
            cht.add_segment(a, b, l, r);
        }
        else {
            auto out = cht.get(l);

            if (out >= llong(1e18) * 3) {
                cout << "INFINITY" << '\n';
            }
            else {
                cout << out << '\n';
            }
        }
    }

    return 0;
};


#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include "../../cht/dynamic_li_chao_tree.hpp"

using namespace std;
using llong = long long;

llong n, q;

const llong INF = 1ll << 60ll;
DynamicLiChaoTree<llong, -1 * INF, INF> cht;

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        llong a, b;
        cin >> a >> b;
        cht.add_line(a, b);
    }

    for (int i = 0; i < q; i++) {
        llong com, x, y;

        cin >> com;
        if (com == 0) {
            cin >> x >> y;
            cht.add_line(x, y);
        }
        else {
            cin >> x;
            cout << cht.get(x) << '\n';
        }
    }

    return 0;
};


#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2444"

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
#include <tuple>
#include "../../segment_tree/segment_tree.hpp"
#include "../../data_type/rolling_hash_monoid.hpp"

using namespace std;
using llong = long long;
using ull = unsigned long long;

llong n, m;
string s;
char com;
string op;
set<tuple<ull, ull, ull>> st;

int main() {
    cin >> n >> m;
    cin >> s;
    SegmentTree<RollingHashMonoid<1710, 10000000007>> seg1(s.begin(), s.end());
    SegmentTree<RollingHashMonoid<1709, 998244353>> seg2(s.begin(), s.end());
    SegmentTree<RollingHashMonoid<1719, 998244353>> seg3(s.begin(), s.end());

    llong l, r;
    l = r = 0;

    for (int i = 0; i < m; i++) {
        cin >> com >> op;

        if (com == 'L') {
            if (op == "++") l++;
            else l--;
        }
        else if (com == 'R') {
            if (op == "++") r++;
            else r--;
        }

        auto key = make_tuple(seg1.fold(l, r + 1).hash,
                              seg2.fold(l, r + 1).hash,
                              seg3.fold(l, r + 1).hash);

        st.insert(key);
    }

    cout << st.size() << endl;
};


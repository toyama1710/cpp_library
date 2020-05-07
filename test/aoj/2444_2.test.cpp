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
#include <utility>
#include "../../string/rolling_hash.hpp"

using namespace std;
using llong = long long;
using ull = unsigned long long;

llong n, m;
string s;
char com;
string op;
set<tuple<ull, ull>> st;

int main() {
    cin >> n >> m;
    cin >> s;

    MRollingHash<1710> rh(s);
    RollingHash<1709, 998244353> h(s);

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

        st.insert(make_tuple(rh.get_hash(l, r + 1), h.get_hash(l, r + 1)));
    }

    cout << st.size() << endl;
};

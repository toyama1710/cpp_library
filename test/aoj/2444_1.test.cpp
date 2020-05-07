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
#include "../../segment_tree/segment_tree.hpp"

using namespace std;
using llong = long long;
using ull = unsigned long long;

llong n, m;
string s;
char com;
string op;
set<tuple<ull, ull, ull>> st;

template<ull base>
struct RollingHash {
    using value_type = pair<ull, ull>;
    using T = value_type;
    
    static std::vector<ull> pow_table;
    inline static T identity() {
        return {0ull, 0ull};
    };
    inline static T operation(const T a, const T b) {
        T ret;
        ret.first = a.first * power(b.second) + b.first;
        ret.second = a.second + b.second;
        return ret;
    };

    inline static ull power(ull n) {
        while (pow_table.size() <= n) pow_table.push_back(pow_table.back() * base);
        return pow_table[n];
    };
};
template<ull base>
vector<ull> RollingHash<base>::pow_table(1, 1);

int main() {
    cin >> n >> m;
    cin >> s;

    SegmentTree<RollingHash<1710>> seg1(n);
    SegmentTree<RollingHash<1000000007>> seg2(n);
    SegmentTree<RollingHash<10134>> seg3(n);
    for (int i = 0; i < n; i++) {
        seg1.update(i, {s[i], 1});
        seg2.update(i, {s[i], 1});
        seg3.update(i, {s[i], 1});
    }

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

        auto key = make_tuple(seg1.fold(l, r + 1).first,
                              seg2.fold(l, r + 1).first,
                              seg3.fold(l, r + 1).first);

        st.insert(key);
    }

    cout << st.size() << endl;
};

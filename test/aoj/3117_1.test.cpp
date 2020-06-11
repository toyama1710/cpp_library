#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3117"

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
#include "../../bbst/set/merge_split_treap.hpp"

using namespace std;
using llong = long long;
using P = pair<llong, llong>;

llong n, k;
Treap<P> st;

int main() {
    cin >> n >> k;

    llong csum = 0;
    llong ans = 0;
    st.insert({0, -1});
    for (int i = 0; i < n; i++) {
        llong a;
        cin >> a;
        a -= k;
        csum += a;
        st.insert({csum, i});
        ans += st.order_of({csum, i});
    }
    cout << ans << endl;

    return 0;
};


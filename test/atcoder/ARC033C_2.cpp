#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc033/tasks/arc033_3"
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
#include "../../bbst/merge_split_set_treap.hpp"

using namespace std;
using llong = long long;

int q;
int t, x;
Treap<llong> st;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> q;
    while (q--) {
        cin >> t >> x;

        if (t == 1) {
            st.insert(x);
        }
        else {
            int idx = st.order_of(x);
            st.erase(st.find_Kth_element(idx));
            cout << idx << '\n';
        }
    }

    return 0;
};


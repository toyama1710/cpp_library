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
#include "../../bbst/set/merge_split_treap.hpp"

using namespace std;
using llong = long long;

int q;
int t, x;
Treap<llong> st;

void dump(Treap<llong>::Node *u, int depth) {
    if (u == nullptr) return;

    dump(u->rch, depth + 4);
    for (int i = 0; i < depth; i++) cout << ' ';
    cout << u->dat << endl;
    dump(u->lch, depth + 4);
}

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
            int dat = st.find_Kth_element(x - 1);
            st.erase(dat);
            cout << dat << '\n';
        }
    }

    return 0;
};


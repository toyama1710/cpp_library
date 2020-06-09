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
#include "../../segment_tree/segment_tree.hpp"
#include "../../data_type/sum_monoid.hpp"

using namespace std;
using llong = long long;

int q;
int t, x;
const int n = 200001;
SegmentTree<SumMonoid<llong>> st(n);

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> q;
    while (q--) {
        cin >> t >> x;

        if (t == 1) {
            st.update(x, st[x] + 1);
        }
        else {
            int idx = st.search(0,
                    [&](llong sum){
                        return sum >= x;
                    });
            st.update(idx, st[idx] - 1);
            cout << idx << '\n';
        }
    }

    return 0;
};


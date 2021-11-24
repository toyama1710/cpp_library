#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C"

#include <iostream>
#include <queue>
#include <string>
#include <tuple>

#include "../../heap/persistent_leftist_heap.hpp"
#include "../../util/reverse_cmp.hpp"

#define _overload(_1, _2, _3, _4, name, ...) name
#define _rep1(Itr, N) _rep3(Itr, 0, N, 1)
#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)
#define _rep3(Itr, a, b, step) for (i64 Itr = a; Itr < b; Itr += step)
#define repeat(...) _overload(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)
#define rep(...) repeat(__VA_ARGS__)

#define ALL(X) begin(X), end(X)

using namespace std;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<PersistentLeftistHeap<i64>> que;
    que.push_back(PersistentLeftistHeap<i64>());
    vector<int> query;

    string s;
    while (cin >> s, s != "end") {
        if (s == "insert") {
            query.push_back(1);
            i64 k;
            cin >> k;
            que.push_back(que.back().push(-k));
        } else {
            query.push_back(0);
            que.push_back(que.back().pop());
        }
    }

    rep(i, (i64)query.size()) {
        if (query[i] == 0) {
            cout << -que[i].peek() << '\n';
        }
    }

    return 0;
}

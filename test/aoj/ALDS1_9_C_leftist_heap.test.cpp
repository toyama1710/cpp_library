#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C"

#include <iostream>
#include <queue>
#include <string>
#include <tuple>

#include "../../heap/leftist_heap.hpp"
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

    LeftistHeap<RevCmp<i64>> que;

    string s;
    while (cin >> s, s != "end") {
        if (s == "insert") {
            i64 k;
            cin >> k;
            if (!que.empty() && que.peek().value() == k)
                que.push(k).pop().push(k).pop();
            que.push(k);
        } else {
            cout << que.peek().value() << '\n';
            que.pop();
        }
        // cout << que.size() << endl;
    }

    return 0;
}

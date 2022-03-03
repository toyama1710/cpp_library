#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include <iostream>

#include "../../hash_map/array_mapped_trie.hpp"
#include "../../util/xorshift.hpp"

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

u64 h(i64 k) {
    xorshift64 rnd(k);
    rnd(); rnd(); rnd();
    return rnd();
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    i64 q;
    cin >> q;

    ArrayMappedTrie<i64, 40, 4> mp;

    rep(_, q) {
        i64 com, k, v;

        cin >> com;

        if (com == 0) {
            cin >> k >> v;
            mp[h(k)] = v;
        } else if (com == 1) {
            cin >> k;
            cout << mp[h(k)] << endl;
        }
    }

    return 0;
}
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

template <class T, class Compare = greater<T> >
using MinHeap = priority_queue<T, vector<T>, Compare>;
template <class T, class Compare = less<T> >
using MaxHeap = priority_queue<T, vector<T>, Compare>;
using llong = long long;

//===
struct PartiallyPersistentUnionFind {
    int turn;
    vector<int> t;
    vector<int> par;
    vector<vector<pair<int, int> > > sz;

    PartiallyPersistentUnionFind(int n)
        : turn(0),
          t(n, -1),
          par(n, -1),
          sz(n, vector<pair<int, int> >(1, make_pair(0, 1))){};

    bool unite(int x, int y) {
        x = find(turn, x);
        y = find(turn, y);
        turn++;

        if (x == y) return false;

        if (par[y] < par[x]) swap(x, y);
        par[x] += par[y];
        par[y] = x;

        t[y] = turn;
        sz[x].push_back(make_pair(turn, -par[x]));

        return true;
    };

    int find(int time, int x) {
        if (par[x] < 0 || t[x] > time) return x;
        return find(time, par[x]);
    };

    bool same(int time, int x, int y) {
        return find(time, x) == find(time, y);
    };

    int size(int time, int x) {
        x = find(time, x);
        return (upper_bound(sz[x].begin(), sz[x].end(),
                            make_pair(time, 1 << 30)) -
                1)
            ->second;
    };
};
//===

int CodeThanksFes2017H() {
    int n, m;
    int a, b;
    int q;
    int x, y;

    cin >> n >> m;
    PartiallyPersistentUnionFind uf(n);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        --a, --b;

        uf.unite(a, b);
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        --x, --y;

        int valid = m + 1;
        int invalid = 0;

        while (valid - invalid > 1) {
            int mid = (valid + invalid) / 2;

            if (uf.same(mid, x, y)) {
                valid = mid;
            } else {
                invalid = mid;
            }
        }

        if (invalid == m) {
            cout << -1 << endl;
        } else {
            cout << valid << endl;
        }
    }

    return 0;
}

int AGC002D() {
    int n, m;
    int a, b;
    int q;
    int x, y, z;

    cin >> n >> m;
    PartiallyPersistentUnionFind uf(n);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--, b--;

        uf.unite(a, b);
    }

    auto f = [&](int t) {
        llong xs = uf.size(t, x);
        llong ys = uf.size(t, y);

        if (uf.same(t, x, y))
            return xs;
        else
            return xs + ys;
    };

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x >> y >> z;
        x--, y--;

        llong valid, invalid;
        llong mid;

        valid = m;
        invalid = 0;
        while (valid - invalid > 1) {
            mid = (valid + invalid) / 2;

            if (f(mid) >= z)
                valid = mid;
            else
                invalid = mid;
        }

        cout << valid << endl;
    }

    return 0;
}

int main() {
    // return CodeThanksFes2017H();
    return AGC002D();
}

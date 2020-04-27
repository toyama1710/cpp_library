#ifndef PERSISTENT_UNION_FIND_HPP
#define PERSISTENT_UNION_FIND_HPP

#include "../array/persistent_array.hpp"

//===
// 0-indexed
template<int K = 2>
struct PersistentUnionFind {
    PersistentArray<int, K> par;

    PersistentUnionFind() = default;
    PersistentUnionFind(int n): par(n, -1) {};
    PersistentUnionFind(PersistentArray<int, K> arr):par(arr) {};

    PersistentUnionFind unite(int x, int y) {
        x = root(x);
        y = root(y);

        if (x == y) return *this;

        if (size(x) > size(y)) {
            return par.set(y, x);
        }
        else {
            return par.set(x, y);
        }
    };

    int root(int x) {
        if (par[x] < 0) return x;
        int res = root(par[x]);
        return res;
    };

    bool same(int x, int y) {
        return root(x) == root(y);
    };

    // return size of set
    int size(int x) {
        x = root(x);
        return -par[x];
    };
};
//===

#endif

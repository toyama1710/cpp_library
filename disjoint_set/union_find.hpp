#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

#include <vector>

//===
struct UnionFind {
    std::vector<int> parent;

    UnionFind() = default;
    UnionFind(int nmemb) {
        init(nmemb);
    };

    void init(int nmemb) {
        parent.clear();
        parent.assign(nmemb, -1);
    };

    int root(int x) {
        if (parent[x] < 0) return x;
        return parent[x] = root(parent[x]);
    };

    void unite(int x, int y) {
        x = root(x);
        y = root(y);

        if (x == y) return;

        if (parent[y] < parent[x]) std::swap(x, y);

        parent[x] += parent[y];
        parent[y] = x;
        
        return;
    };
    
    bool same(int x, int y) {
        return root(x) == root(y);
    };
    int size(int x) {
        return -(parent[root(x)]);
    };
};
//===

#endif

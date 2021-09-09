#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

#include <vector>
#include <utility>

//===
struct UnionFind {
    std::vector<int> parent;

    UnionFind() = default;
    UnionFind(int nmemb) {
        init(nmemb);
    };

    void init(int nmemb) {
        parent.clear();
        parent.resize(nmemb, -1);
    };

    int represent(int x) {
        if (parent[x] < 0) return x;
        return parent[x] = represent(parent[x]);
    };

    void unite(int x, int y) {
        x = represent(x);
        y = represent(y);

        if (x == y) return;

        if (parent[y] < parent[x]) std::swap(x, y);

        parent[x] += parent[y];
        parent[y] = x;
        
        return;
    };
    
    bool same(int x, int y) {
        return represent(x) == represent(y);
    };
    int size(int x) {
        return -(parent[represent(x)]);
    };
};
//===

#endif

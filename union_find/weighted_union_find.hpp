#ifndef WEIGHTED_UNION_FIND_HPP
#define WEIGHTED_UNION_FIND_HPP
#include <vector>

//===
template<class Abel>
struct WeightedUnionFind {
    using T = typename Abel::value_type;

    std::vector<int> parent; // [i] = i-th node's parent. if [i] < 0, i-th node is root.
    std::vector<T> diff_weight; // distance from parent
    
    WeightedUnionFind() = default;
    WeightedUnionFind(int nmemb) {
        init(nmemb);
    };

    void init(int nmemb) {
        parent.resize(nmemb, -1);
        diff_weight.resize(nmemb, Abel::identity());
    };

    int root(int x) {
        if (parent[x] < 0) return x;
        
        int p = root(parent[x]);
        diff_weight[x] = Abel::operation(diff_weight[x], diff_weight[parent[x]]);
        parent[x] = p;

        return p;
    };

    // unite x, y; weight(y) - weight(x) = w
    bool unite(int x, int y, T w) {
        T wx = weight(x);
        T wy = weight(y);
        x = root(x);
        y = root(y);

        if (x == y) return false;
        w = Abel::operation(w, wx);
        w = Abel::operation(w, Abel::inverse(wy));
        if (size(x) < size(y)) std::swap(x, y), w = Abel::inverse(w);

        parent[x] += parent[y];
        parent[y] = x;
        diff_weight[y] = w;
        
        return true;
    };
    
    bool same(int x, int y) {
        return root(x) == root(y);
    };

    T weight(int x) {
        root(x);
        return diff_weight[x];
    };

    T diff(int x, int y) {
        return Abel::operation(weight(y),
                Abel::inverse(weight(x)));
    };

    int size(int x) {
        return -parent[root(x)];
    };
};
//===

#endif

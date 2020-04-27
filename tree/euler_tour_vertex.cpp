#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

//===
struct EulerTour4Vertex {
    vector<int> ls, rs;
    vector<vector<int> > G;

    EulerTour4Vertex(int n):
        ls(n), rs(n), G(n) {};
    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    };
    void build(int root = 0) {
        int pos = 0;
        dfs(root, -1, pos);
    };
    void dfs(int v, int par, int &pos) {
        ls[v] = pos++;
        for (int u:G[v]) {
            if (u != par) dfs(u, v, pos);
        }
        rs[v] = pos;
    };

    int idx(int u) {
        return ls[u];
    };

    //fold(subTree(r))
    //f folds [l, r)
    template<class F>
    void exec(int r, F f) {
        f(ls[r], rs[r]);
    };
};
using EulerTourForVertex = EulerTour4Vertex;
//===

template<typename Monoid, typename OP = function<Monoid(Monoid, Monoid)> >
struct SegmentTree {
    //    using OP = function<Monoid(Monoid, Monoid)>;
    
    vector<Monoid> tree;
    int size;
    const OP merge_monoid; // bin' operation
    const Monoid e; // neutral element
                                           
    SegmentTree(int nmemb, const Monoid &e, const OP &f):
        size(nmemb), merge_monoid(f), e(e)
    {
        tree.assign(size << 1, e);
    }

    template<class InputIterator>
    SegmentTree(InputIterator first, InputIterator last,
                const Monoid &e, const OP &f):
        size(distance(first, last)), merge_monoid(f), e(e)
    {
        tree.resize(size << 1);
        int i;

        i = size;
        for (InputIterator itr = first; itr != last; itr++) {
            tree[i++] = *itr;
        }

        for (i = size - 1; i > 0; i--) {
            tree[i] = merge_monoid(tree[(i << 1)], tree[(i << 1) | 1]);
        }
    }

    inline void update(int k, Monoid dat) {
        k += size;
        tree[k] = dat;
        
        while(k > 1) {
            k >>= 1;
            tree[k] = merge_monoid(tree[(k << 1)], tree[(k << 1) | 1]);
        }
    }

    // [l, r)
    inline Monoid fold(int l, int r) {
        l += size; //points leaf
        r += size;

        Monoid lv = e;
        Monoid rv = e;
        while (l < r) {
            if (l & 1) lv = merge_monoid(lv, tree[l++]);
            if (r & 1) rv = merge_monoid(tree[--r], rv);

            l >>= 1;
            r >>= 1;
        }

        return merge_monoid(lv, rv);
    };

    inline Monoid operator[] (const int k) const {
        return tree[k + size];
    };
};
//===

int yosupo_vertex_add_subtree_sum() {
    return 0;
};

int main() {
    return yosupo_vertex_add_subtree_sum();
};

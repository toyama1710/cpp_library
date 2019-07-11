#include <iostream>
#include <vector>
using namespace std;

//===
template<Typename Abel>
struct UnionFind {
    vector<int> parent;
    vector<Abel> diff_wetght; //e‚©‚ç‚Ì‹——£

    UnionFind(){}
    
    UnionFind(int nmemb)
    {
        init(nmemb);
    }

    void init(int nmemb)
    {
        parent.clear();
        parent.assign(nmemb, -1);
    }

    int root(int x)
    {
        if (parent[x] < 0) {
            return x;
        }
        return parent[x] = root(parent[x]);
    }

    bool same(int x, int y)
    {
        return root(x) == root(y);
    }

    void unite(int x, int y)
    {
        x = root(x);
        y = root(y);

        if (x == y) return;

        parent[x] += parent[y];
        parent[y] = x;
        
        return;
    }
};
//===

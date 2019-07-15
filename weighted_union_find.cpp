#include <iostream>
#include <vector>
#include <functional>
using namespace std;

//===
template<typename Abel>
struct WeightedUnionFind {
    using OP = function<Abel(Abel, Abel)>;

    vector<int> parent;
    vector<Abel> diff_weight; //êeÇ©ÇÁÇÃãóó£
    const OP add;
    const OP sub;
    const Abel e;
    
    WeightedUnionFind(){};

    WeightedUnionFind(int nmemb,
                      const Abel &e = 0,
                      const OP &add = [](Abel x, Abel y){return x+y;},
                      const OP &sub = [](Abel x, Abel y){return x-y;}):
        add(add),
        sub(sub),
        e(e)
    {
        parent.assign(nmemb, -1);
        diff_weight.assign(nmemb, e);
    }

    int root(int x)
    {
        if (parent[x] < 0) {
            return x;
        }
        
        int p = root(parent[x]);
        diff_weight[x] = add(diff_weight[x], diff_weight[parent[x]]);
        parent[x] = p;

        return p;
    }

    bool same(int x, int y)
    {
        return root(x) == root(y);
    }
    
    bool unite(int x, int y, Abel w)
    {
        Abel wx = weight(x);
        Abel wy = weight(y);

        x = root(x);
        y = root(y);

        if (x == y) return false;

        w = sub(add(w, wx), wy);

        parent[x] += parent[y];
        parent[y] = x;
        diff_weight[y] = w;
        
        return true;
    }
    
    Abel weight(int x)
    {
        root(x);
        return diff_weight[x];
    }

    Abel diff(int x, int y)
    {
        return sub(weight(y), weight(x));
    }

    int size(int x)
    {
        x = root(x);
        return -parent[x];
    }
};
//===

typedef long long ll;

// verify AtCoder Beginner Contest 087 D
// https://atcoder.jp/contests/abc087/submissions/6393566
int abc087D(void)
{
    WeightedUnionFind<ll> uf(1000005);
    ll n, m;
    ll l, r, d;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> l >> r >> d;

        uf.unite(l, r, d);

        if (uf.diff(l, r) != d) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}

int main()
{
    return abc087D();
}

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
template<class T, class Compare = less<T> >
using MaxHeap = priority_queue<T, vector<T>, Compare>;
template<class T, class Compare = greater<T> >
using MinHeap = priority_queue<T, vector<T>, Compare>;
using llong = long long;

//===
struct HeavyLightDecomposition {
private:
    vector<vector<int> > G; // UnWeightedGraph
    vector<int> head; // root of heavy-edge
    vector<int> par;
    vector<int> sz;

    void convert_rooted_tree(int v) {
        int sz[v] = 1;
        for (int u:G[v]) {
            if (par[v] == u) continue;
            par[u] = v;
            convert_rooted_tree(u);
            sz[v] += sz[u];
        }
    };

public:
    HeavyLightDecomposition(int n):
        G(n)
    {};
    
    void build(vector<int> rs = {0}) {
        for (int r:rs) {
            convert_rooted_tree(r);
            head[r] = r;
            dfs(r);
        }
    };
    
    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    };
    int lca(int u, int v) {
    };
    int distance(int u, int v) {
    };

    //return range on EulerTour
    vector<pair<int, int> > get_ranges(int u, int v) { //vertex
    };
};
//===

int main() {

    return 0;
}

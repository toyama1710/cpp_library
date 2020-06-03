---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :x: test/yosupo/union_find.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/union_find.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-03 06:37:29+00:00


* see: <a href="https://judge.yosupo.jp/problem/unionfind">https://judge.yosupo.jp/problem/unionfind</a>


## Depends on

* :x: <a href="../../../library/disjoint_set/union_find.hpp.html">disjoint_set/union_find.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
// header file section
#include <iostream>
#include <cstdio>
#include <cfloat>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <algorithm>
#include "../../disjoint_set/union_find.hpp"

using namespace std;
using llong = long long;

llong n, q;
llong com, u, v;
UnionFind uf;

int main() {
    cin >> n >> q;
    uf.init(n);

    while (q--) {
        cin >> com >> u >> v;

        if (com == 0) {
            uf.unite(u, v);
        }
        else {
            cout << uf.same(u, v) ? 1 : 0 << '\n';
        }
    }

    return 0;
};


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/union_find.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
// header file section
#include <iostream>
#include <cstdio>
#include <cfloat>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <algorithm>
#line 1 "disjoint_set/union_find.hpp"



#line 5 "disjoint_set/union_find.hpp"

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


#line 16 "test/yosupo/union_find.test.cpp"

using namespace std;
using llong = long long;

llong n, q;
llong com, u, v;
UnionFind uf;

int main() {
    cin >> n >> q;
    uf.init(n);

    while (q--) {
        cin >> com >> u >> v;

        if (com == 0) {
            uf.unite(u, v);
        }
        else {
            cout << uf.same(u, v) ? 1 : 0 << '\n';
        }
    }

    return 0;
};


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>


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


# :heavy_check_mark: test/aoj/DSL1B.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL1B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-04 02:44:42+00:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/disjoint_set/weighted_union_find.hpp.html">disjoint_set/weighted_union_find.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

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
#include "../../disjoint_set/weighted_union_find.hpp"

using namespace std;
using llong = long long;

struct A {
    using T = llong;
    using value_type = T;

    static inline T identity() {
        return 0;
    };

    static inline T operation(T x, T y) {
        return x + y;
    };

    static inline T inverse(T x) {
        return -x;
    };
};

llong n, q;
llong com, x, y, w;

int main() {
    cin >> n >> q;
    WeightedUnionFind<A> uf(n);

    while (q--) {
        cin >> com;

        if (com == 0) {
            cin >> x >> y >> w;
            uf.unite(x, y, w);
        }
        else {
            cin >> x >> y;

            if (uf.same(x, y)) {
                cout << uf.diff(x, y) << '\n';
            }
            else {
                cout << "?\n";
            }
        }
    }

    return 0;
};


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL1B.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

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
#line 1 "disjoint_set/weighted_union_find.hpp"


#line 4 "disjoint_set/weighted_union_find.hpp"

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


#line 17 "test/aoj/DSL1B.test.cpp"

using namespace std;
using llong = long long;

struct A {
    using T = llong;
    using value_type = T;

    static inline T identity() {
        return 0;
    };

    static inline T operation(T x, T y) {
        return x + y;
    };

    static inline T inverse(T x) {
        return -x;
    };
};

llong n, q;
llong com, x, y, w;

int main() {
    cin >> n >> q;
    WeightedUnionFind<A> uf(n);

    while (q--) {
        cin >> com;

        if (com == 0) {
            cin >> x >> y >> w;
            uf.unite(x, y, w);
        }
        else {
            cin >> x >> y;

            if (uf.same(x, y)) {
                cout << uf.diff(x, y) << '\n';
            }
            else {
                cout << "?\n";
            }
        }
    }

    return 0;
};


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>


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


# :heavy_check_mark: test/yosupo/persistent_union_find.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/persistent_union_find.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 16:23:31+09:00


* see: <a href="https://judge.yosupo.jp/problem/persistent_unionfind">https://judge.yosupo.jp/problem/persistent_unionfind</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/array/persistent_array.hpp.html">array/persistent_array.hpp</a>
* :heavy_check_mark: <a href="../../../library/disjoint_set/persistent_union_find.hpp.html">disjoint_set/persistent_union_find.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

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
#include "../../disjoint_set/persistent_union_find.hpp"

using namespace std;
using llong = long long;
using UF = PersistentUnionFind<32>;

llong n, q;
llong t, k, u, v;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cin >> n >> q;

    vector<UF> uf(q);
    uf[0] = UF(n);
    
    for (int i = 1; i <= q; i++) {
        cin >> t >> k >> u >> v;
        k++;

        if (t == 0) {
            uf[i] = uf[k].unite(u, v);
        }
        else if (t == 1) {
            if (uf[k].same(u, v)) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
    }
     
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/persistent_union_find.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

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
#line 1 "disjoint_set/persistent_union_find.hpp"



#line 1 "array/persistent_array.hpp"



#include <memory>
#include <cstring>
#line 7 "array/persistent_array.hpp"

//===
// #include <memory>
// #include <cstring>
// #include <algorithm>
// K-ary tree
template<class T, int K = 2, template<class> class Alloc = std::allocator>
struct PersistentArray {
    struct Node;
    using Leaf = T;
    struct Node {
        T dat;
        Node* ch[K] = {};

        Node() = default;
        Node(Node *np) {
            dat = np->dat;
            std::memcpy(ch, np->ch, sizeof(Node *) * K);
        };
    };

    Node *root = nullptr;
    int arr_size = 0;

    PersistentArray() = default;
    PersistentArray (Node *root, int arr_size):root(root), arr_size(arr_size) {};
    PersistentArray(int size, const T &d = T()):arr_size(size) {
        root = new Node();
        init(root, size, d);
    };
    Node *init(Node *np, int size, T d) {
        np->dat = d;
                             
        if (size == 1) return np;
        for (int i = 0; i < std::min(K, size); i++) {
            np->ch[i] = init(new Node(), (size + K - 1) / K, d);
        }
        return np;
    };

    const T get(int idx) const {
        return get(idx, root);
    };
    const T get(int idx, Node *np) const {
        if (idx == 0) return np->dat;
        return get((idx - 1) / K, np->ch[idx % K]);
    };
    
    PersistentArray set(int idx, const T &val) {
        return {set(idx, val, root), arr_size};
    };
    Node *set(int idx, const T &val, Node *np) {
        if (idx == 0) {
            Node *node = new Node(np);
            node->dat = val;
            return node;
        }
        else {
            Node *node = new Node(np);
            node->ch[idx % K] = set((idx - 1) / K, val, np->ch[idx % K]);
            return node;
        }
    };

    void destructive_set(int idx, const T &val) {
        destructive_set(idx, val, root);
    };
    void destructive_set(int idx, const T &val, Node *np) {
        if (idx == 0) np->dat = val;
        else destructive_set((idx - 1) / K, val, np->ch[idx % K]);
    };

    int size() {
        return arr_size;
    };
    PersistentArray get_array() {
        return *this;
    };
    
    const T operator [] (int idx) const {
        return get(idx, root);
    };
};
//===


#line 5 "disjoint_set/persistent_union_find.hpp"

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
            auto tmp = par.set(x, par[x] + par[y]);
            return tmp.set(y, x);
        }
        else {
            auto tmp = par.set(y, par[y] + par[x]);
            return tmp.set(x, y);
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
        return -par[root(x)];
    };
};
//===


#line 17 "test/yosupo/persistent_union_find.test.cpp"

using namespace std;
using llong = long long;
using UF = PersistentUnionFind<32>;

llong n, q;
llong t, k, u, v;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cin >> n >> q;

    vector<UF> uf(q);
    uf[0] = UF(n);
    
    for (int i = 1; i <= q; i++) {
        cin >> t >> k >> u >> v;
        k++;

        if (t == 0) {
            uf[i] = uf[k].unite(u, v);
        }
        else if (t == 1) {
            if (uf[k].same(u, v)) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
    }
     
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>


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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: sparse_table/disjoint_sparse_table.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#cb323a14df0a258a78d4acbe3d02dfda">sparse_table</a>
* <a href="{{ site.github.repository_url }}/blob/master/sparse_table/disjoint_sparse_table.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 13:16:14+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <vector>
using namespace std;
using llong = long long;

//===
template <class SemiGroup,
          class Merge = function<SemiGroup(SemiGroup, SemiGroup)>>
struct DisjointSparseTable {
    static int msb(int x) {
#ifndef __has_builtin
        // (r |= a) == (r += a)
        int r = 0;
        if (x >> 16) x >>= 16, r |= 16;
        if (x >> 8) x >>= 8, r |= 8;
        if (x >> 4) x >>= 4, r |= 4;
        if (x >> 2) x >>= 2, r |= 2;
        return r | (x >> 1);
#else
        return 31 - __builtin_clz(x);
#endif
    };

    bool builded = false;
    Merge f;
    int sz;
    vector<vector<SemiGroup>> table;
    vector<int> msb_table;

    DisjointSparseTable(int n, SemiGroup d, Merge f): sz(n), f(f) {
        table.emplace_back(n, d);
        builded = false;
    }
    template<class InputItr>
    DisjointSparseTable(InputItr first, InputItr last, Merge f) {
        table.emplace_back(first, last);
        sz = table[0].size();

        build();
    };

    void build() {
        msb_table[0] = 1;
        for (int i = 1; i < sz; i <<= 1) {
            msb_table[i] = msb_table[i - 1] + 1;
            for (int j = i + 1; j < (i << 1); j++) {
                msb_table[j] = msb_table[i];
            }
        }
        for (int i = 2; i < sz; i <<= 1) {
            
        }
    };
    void set(int idx, SemiGroup d) {
        assert(idx >= 0 && idx < sz);
        table[0][idx] = d;
        builded = false;
    };

    SemiGroup fold(int l, int r) {
        assert(l < r);
        assert(l >= 0 && r <= sz);
        assert(builded);
    };
    SemiGroup fold(int l, int r, SemiGroup e) {
        if (l >= r) return e;
        return fold(l, r);
    };
};
//===

int main() {

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "sparse_table/disjoint_sparse_table.cpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <vector>
using namespace std;
using llong = long long;

//===
template <class SemiGroup,
          class Merge = function<SemiGroup(SemiGroup, SemiGroup)>>
struct DisjointSparseTable {
    static int msb(int x) {
#ifndef __has_builtin
        // (r |= a) == (r += a)
        int r = 0;
        if (x >> 16) x >>= 16, r |= 16;
        if (x >> 8) x >>= 8, r |= 8;
        if (x >> 4) x >>= 4, r |= 4;
        if (x >> 2) x >>= 2, r |= 2;
        return r | (x >> 1);
#else
        return 31 - __builtin_clz(x);
#endif
    };

    bool builded = false;
    Merge f;
    int sz;
    vector<vector<SemiGroup>> table;
    vector<int> msb_table;

    DisjointSparseTable(int n, SemiGroup d, Merge f): sz(n), f(f) {
        table.emplace_back(n, d);
        builded = false;
    }
    template<class InputItr>
    DisjointSparseTable(InputItr first, InputItr last, Merge f) {
        table.emplace_back(first, last);
        sz = table[0].size();

        build();
    };

    void build() {
        msb_table[0] = 1;
        for (int i = 1; i < sz; i <<= 1) {
            msb_table[i] = msb_table[i - 1] + 1;
            for (int j = i + 1; j < (i << 1); j++) {
                msb_table[j] = msb_table[i];
            }
        }
        for (int i = 2; i < sz; i <<= 1) {
            
        }
    };
    void set(int idx, SemiGroup d) {
        assert(idx >= 0 && idx < sz);
        table[0][idx] = d;
        builded = false;
    };

    SemiGroup fold(int l, int r) {
        assert(l < r);
        assert(l >= 0 && r <= sz);
        assert(builded);
    };
    SemiGroup fold(int l, int r, SemiGroup e) {
        if (l >= r) return e;
        return fold(l, r);
    };
};
//===

int main() {

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


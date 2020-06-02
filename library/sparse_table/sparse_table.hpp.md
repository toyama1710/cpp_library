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


# :x: sparse_table/sparse_table.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#cb323a14df0a258a78d4acbe3d02dfda">sparse_table</a>
* <a href="{{ site.github.repository_url }}/blob/master/sparse_table/sparse_table.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-03 08:26:16+09:00




## Verified with

* :x: <a href="../../verify/test/yosupo/static_rmq.test.cpp.html">test/yosupo/static_rmq.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef SPARSE_TABLE_HPP
#define SPARSE_TABLE_HPP

#include <functional>
#include <vector>
#include <iterator>

//===
template<class SemiLattice>
struct SparseTable {
    using S = SemiLattice;
    using T = typename SemiLattice::value_type;

    std::vector<std::vector<T>> table;
    std::vector<size_t> log2;

    SparseTable() = default;

    template<class InputItr>
    SparseTable(InputItr first, InputItr last) {
        int n = std::distance(first, last);
        log2.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) log2[i] = log2[(i - 1) / 2] + 1;
        
        table.reserve(log2[n] + 1);
        table.emplace_back(first, last);

        for (int i = 1; (1 << i) <= n; i++) {
            int w = 1 << (i - 1);
            table.emplace_back();
            table.back().reserve(n - (1 << i) + 1);
            for (int j = 0; j + (1 << i) <= n; j++) {
                table[i].emplace_back(S::operation(table[i - 1][j], table[i - 1][j + w]));
            }
        }
    };

    //[l, r)
    T fold(int l, int r) {
        int k = log2[r - l];
        return S::operation(table[k][l], table[k][r - (1 << k)]);
    };

    int size() {
        return table[0].size();
    };

    T operator[] (const int k) {
        return table[0][k];
    };
};
//===

#endif
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "sparse_table/sparse_table.hpp"



#include <functional>
#include <vector>
#include <iterator>

//===
template<class SemiLattice>
struct SparseTable {
    using S = SemiLattice;
    using T = typename SemiLattice::value_type;

    std::vector<std::vector<T>> table;
    std::vector<size_t> log2;

    SparseTable() = default;

    template<class InputItr>
    SparseTable(InputItr first, InputItr last) {
        int n = std::distance(first, last);
        log2.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) log2[i] = log2[(i - 1) / 2] + 1;
        
        table.reserve(log2[n] + 1);
        table.emplace_back(first, last);

        for (int i = 1; (1 << i) <= n; i++) {
            int w = 1 << (i - 1);
            table.emplace_back();
            table.back().reserve(n - (1 << i) + 1);
            for (int j = 0; j + (1 << i) <= n; j++) {
                table[i].emplace_back(S::operation(table[i - 1][j], table[i - 1][j + w]));
            }
        }
    };

    //[l, r)
    T fold(int l, int r) {
        int k = log2[r - l];
        return S::operation(table[k][l], table[k][r - (1 << k)]);
    };

    int size() {
        return table[0].size();
    };

    T operator[] (const int k) {
        return table[0][k];
    };
};
//===



```
{% endraw %}

<a href="../../index.html">Back to top page</a>


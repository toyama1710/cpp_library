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


# :heavy_check_mark: disjoint_set/weighted_union_find.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#334b410b60c6352c539a44a5cc4509bc">disjoint_set</a>
* <a href="{{ site.github.repository_url }}/blob/master/disjoint_set/weighted_union_find.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-04 02:44:42+00:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL1B.test.cpp.html">test/aoj/DSL1B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "disjoint_set/weighted_union_find.hpp"


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



```
{% endraw %}

<a href="../../index.html">Back to top page</a>


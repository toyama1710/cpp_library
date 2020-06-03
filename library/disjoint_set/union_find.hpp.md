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


# :x: disjoint_set/union_find.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#334b410b60c6352c539a44a5cc4509bc">disjoint_set</a>
* <a href="{{ site.github.repository_url }}/blob/master/disjoint_set/union_find.hpp">View this file on GitHub</a>
    - Last commit date: 2020-06-03 06:37:29+00:00




## Verified with

* :x: <a href="../../verify/test/yosupo/union_find.test.cpp.html">test/yosupo/union_find.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef UNION_FIND_HPP
#define UNION_FIND_HPP

#include <vector>

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

#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "disjoint_set/union_find.hpp"



#include <vector>

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



```
{% endraw %}

<a href="../../index.html">Back to top page</a>


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


# :heavy_check_mark: segment_tree/persistent_segment_tree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ca810e3a5259e4bd613e780cf209098c">segment_tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/segment_tree/persistent_segment_tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-09 16:11:51+00:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/rectangle_sum1.test.cpp.html">test/yosupo/rectangle_sum1.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef PERSISTENT_SEGMENT_TREE_HPP
#define PERSISTENT_SEGMENT_TREE_HPP

#include <iterator>
#include <functional>
#include <vector>
#include <cstdint>
#include <cstddef>

//===
// LIBRARY SECTION
template<class Monoid>
struct PersistentSegmentTree {
    using uint = size_t;
    using T = typename Monoid::value_type;
    
    struct Node {
        T dat;
        Node *l = nullptr, *r = nullptr;

        Node (T dat):dat(dat) {};
    };
    
    Node *root;
    uint n;

    Node *merge_node(Node *lch, Node *rch) {
        T l = (lch ? lch->dat : Monoid::identity());
        T r = (rch ? rch->dat : Monoid::identity());
        Node *ret = new Node(Monoid::operation(l, r));
        ret->l = lch;
        ret->r = rch;

        return ret;
    };

    PersistentSegmentTree(const PersistentSegmentTree &) = default;
    PersistentSegmentTree &operator = (const PersistentSegmentTree &) = default;
    PersistentSegmentTree(uint n, Node *r):n(n), root(r) {};
    PersistentSegmentTree(uint n)
        :n(n), root(alloc(0, n, std::vector<T>(n, Monoid::identity()))) {};
    template<class InputItr>
    PersistentSegmentTree(const InputItr first, const InputItr last)
        :n(std::distance(first, last)), root(alloc(0, n, std::vector<T>(first, last))) {};

    Node *alloc(uint nl, uint nr, const std::vector<T> &v) {
        if (nr - nl <= 1) return new Node(v[nl]);
        else return merge_node(alloc(nl, (nl + nr) / 2, v),
                alloc((nl + nr) / 2, nr, v));
    };

    const T fold(uint l, uint r) const {
        return fold(l, r, 0, n, root);
    };
    const T fold(uint ql, uint qr, uint nl, uint nr, const Node *np) const {
        if (np == nullptr || qr <= nl || nr <= ql) return Monoid::identity();
        else if (ql <= nl && nr <= qr) return np->dat;
        else return Monoid::operation(fold(ql, qr, nl, (nl + nr) / 2, np->l), fold(ql, qr, (nl + nr) / 2, nr, np->r));
    };

    PersistentSegmentTree update(uint idx, T d) {
        return set(idx, d);
    };
    PersistentSegmentTree set(uint idx, T d) {
        return PersistentSegmentTree(n, update(0, n, idx, d, root));
    };
    Node *update(uint nl, uint nr, uint idx, T d, Node *np) {
        if (idx < nl || nr <= idx) return np;
        else if (nr - nl == 1) return new Node(d);
        else return merge_node(update(nl, (nl + nr) / 2, idx, d, np->l), update((nl + nr) / 2, nr, idx, d, np->r));
    };

    PersistentSegmentTree get_tree() {
        return *this;
    };

    T operator [] (uint idx) {
        return fold(idx, idx + 1, 0, n, root);
    };

};
//===

#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "segment_tree/persistent_segment_tree.hpp"



#include <iterator>
#include <functional>
#include <vector>
#include <cstdint>
#include <cstddef>

//===
// LIBRARY SECTION
template<class Monoid>
struct PersistentSegmentTree {
    using uint = size_t;
    using T = typename Monoid::value_type;
    
    struct Node {
        T dat;
        Node *l = nullptr, *r = nullptr;

        Node (T dat):dat(dat) {};
    };
    
    Node *root;
    uint n;

    Node *merge_node(Node *lch, Node *rch) {
        T l = (lch ? lch->dat : Monoid::identity());
        T r = (rch ? rch->dat : Monoid::identity());
        Node *ret = new Node(Monoid::operation(l, r));
        ret->l = lch;
        ret->r = rch;

        return ret;
    };

    PersistentSegmentTree(const PersistentSegmentTree &) = default;
    PersistentSegmentTree &operator = (const PersistentSegmentTree &) = default;
    PersistentSegmentTree(uint n, Node *r):n(n), root(r) {};
    PersistentSegmentTree(uint n)
        :n(n), root(alloc(0, n, std::vector<T>(n, Monoid::identity()))) {};
    template<class InputItr>
    PersistentSegmentTree(const InputItr first, const InputItr last)
        :n(std::distance(first, last)), root(alloc(0, n, std::vector<T>(first, last))) {};

    Node *alloc(uint nl, uint nr, const std::vector<T> &v) {
        if (nr - nl <= 1) return new Node(v[nl]);
        else return merge_node(alloc(nl, (nl + nr) / 2, v),
                alloc((nl + nr) / 2, nr, v));
    };

    const T fold(uint l, uint r) const {
        return fold(l, r, 0, n, root);
    };
    const T fold(uint ql, uint qr, uint nl, uint nr, const Node *np) const {
        if (np == nullptr || qr <= nl || nr <= ql) return Monoid::identity();
        else if (ql <= nl && nr <= qr) return np->dat;
        else return Monoid::operation(fold(ql, qr, nl, (nl + nr) / 2, np->l), fold(ql, qr, (nl + nr) / 2, nr, np->r));
    };

    PersistentSegmentTree update(uint idx, T d) {
        return set(idx, d);
    };
    PersistentSegmentTree set(uint idx, T d) {
        return PersistentSegmentTree(n, update(0, n, idx, d, root));
    };
    Node *update(uint nl, uint nr, uint idx, T d, Node *np) {
        if (idx < nl || nr <= idx) return np;
        else if (nr - nl == 1) return new Node(d);
        else return merge_node(update(nl, (nl + nr) / 2, idx, d, np->l), update((nl + nr) / 2, nr, idx, d, np->r));
    };

    PersistentSegmentTree get_tree() {
        return *this;
    };

    T operator [] (uint idx) {
        return fold(idx, idx + 1, 0, n, root);
    };

};
//===



```
{% endraw %}

<a href="../../index.html">Back to top page</a>


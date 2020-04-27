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


# :x: array/persistent_array.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f1f713c9e000f5d3f280adbd124df4f5">array</a>
* <a href="{{ site.github.repository_url }}/blob/master/array/persistent_array.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 15:25:45+09:00




## Required by

* :x: <a href="../disjoint_set/persistent_union_find.hpp.html">disjoint_set/persistent_union_find.hpp</a>


## Verified with

* :x: <a href="../../verify/test/yosupo/persistent_union_find.test.cpp.html">test/yosupo/persistent_union_find.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef PERSISTENT_ARRAY_HPP
#define PERSISTENT_ARRAY_HPP

#include <memory>
#include <cstring>
#include <algorithm>

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

    T get(int idx) {
        return get(idx, root);
    };
    T get(int idx, Node *np) {
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

#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "array/persistent_array.hpp"



#include <memory>
#include <cstring>
#include <algorithm>

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

    T get(int idx) {
        return get(idx, root);
    };
    T get(int idx, Node *np) {
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



```
{% endraw %}

<a href="../../index.html">Back to top page</a>


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


# :warning: array/persistent_array2.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f1f713c9e000f5d3f280adbd124df4f5">array</a>
* <a href="{{ site.github.repository_url }}/blob/master/array/persistent_array2.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-18 12:55:17+00:00




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
// LIBRARY SECTION

// #include <memory>
// #include <cstring>
// #include <algorithm>
// binary tree
template<class T>
struct PersistentArray {
    struct Node;
    using Leaf = T;
    struct Node {
        T dat;
        Node* ch[2] = {};

        Node() = default;
        Node(Node *np) {
            dat = np->dat;
            ch[0] = np->ch[0];
            ch[1] = np->ch[1];
        };
    };

    Node *root = nullptr;
    int arr_size = 0;

    PersistentArray() = default;
    PersistentArray (Node *root, int arr_size):root(root), arr_size(arr_size) {};
    PersistentArray(int size, const T &d = T()) {
        arr_size = 1;
        while (arr_size < size) arr_size *= 2;
        root = new Node();
        init(root, arr_size, d);
    };
    Node *init(Node *np, int size, T d) {
        if (size == 1) {
            np->dat = d;
            return np;
        }
        np->ch[0] = init(new Node(), size / 2, d);
        np->ch[1] = init(new Node(), size / 2, d);
        return np;
    };

    const T get(int idx) const {
        return get(idx, 0, arr_size, root);
    };
    const T get(int idx, int l, int r, Node *np) const {
        if (r - l <= 1) return np->dat;

        if (idx < (r - l) / 2) return get(idx, l, (l + r) / 2, np->ch[0]);
        else return get(idx, (l + r) / 2, r, np->ch[1]);
    };
    
    PersistentArray set(int idx, const T &val) {
        return {set(idx, int l, int r, val, root), arr_size};
    };
    Node *set(int idx, int l, int r, const T &val, Node *np) {
        if (r - l == 1) {
            Node *node = new Node(np);
            node->dat = val;
            return node;
        }
        else {
            Node *node = new Node(np);

            if (idx < (l + r) / 2) node->ch[0] = set(idx, l, (l + r) / 2, np->ch[0]);
            else node->ch[1] = set(idx, (l + r) / 2, r, np->ch[1]);

            return node;
        }
    };

    int size() {
        return arr_size;
    };
    PersistentArray get_array() {
        return *this;
    };
    
    const T operator [] (int idx) const {
        return get(idx);
    };
};
//===

#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "array/persistent_array2.hpp"



#include <memory>
#include <cstring>
#include <algorithm>

//===
// LIBRARY SECTION

// #include <memory>
// #include <cstring>
// #include <algorithm>
// binary tree
template<class T>
struct PersistentArray {
    struct Node;
    using Leaf = T;
    struct Node {
        T dat;
        Node* ch[2] = {};

        Node() = default;
        Node(Node *np) {
            dat = np->dat;
            ch[0] = np->ch[0];
            ch[1] = np->ch[1];
        };
    };

    Node *root = nullptr;
    int arr_size = 0;

    PersistentArray() = default;
    PersistentArray (Node *root, int arr_size):root(root), arr_size(arr_size) {};
    PersistentArray(int size, const T &d = T()) {
        arr_size = 1;
        while (arr_size < size) arr_size *= 2;
        root = new Node();
        init(root, arr_size, d);
    };
    Node *init(Node *np, int size, T d) {
        if (size == 1) {
            np->dat = d;
            return np;
        }
        np->ch[0] = init(new Node(), size / 2, d);
        np->ch[1] = init(new Node(), size / 2, d);
        return np;
    };

    const T get(int idx) const {
        return get(idx, 0, arr_size, root);
    };
    const T get(int idx, int l, int r, Node *np) const {
        if (r - l <= 1) return np->dat;

        if (idx < (r - l) / 2) return get(idx, l, (l + r) / 2, np->ch[0]);
        else return get(idx, (l + r) / 2, r, np->ch[1]);
    };
    
    PersistentArray set(int idx, const T &val) {
        return {set(idx, int l, int r, val, root), arr_size};
    };
    Node *set(int idx, int l, int r, const T &val, Node *np) {
        if (r - l == 1) {
            Node *node = new Node(np);
            node->dat = val;
            return node;
        }
        else {
            Node *node = new Node(np);

            if (idx < (l + r) / 2) node->ch[0] = set(idx, l, (l + r) / 2, np->ch[0]);
            else node->ch[1] = set(idx, (l + r) / 2, r, np->ch[1]);

            return node;
        }
    };

    int size() {
        return arr_size;
    };
    PersistentArray get_array() {
        return *this;
    };
    
    const T operator [] (int idx) const {
        return get(idx);
    };
};
//===



```
{% endraw %}

<a href="../../index.html">Back to top page</a>


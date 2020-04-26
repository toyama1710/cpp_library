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


# :warning: heap/meldable_heap.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4d4a9aa362b6ffe089fd2e992ccf4f5f">heap</a>
* <a href="{{ site.github.repository_url }}/blob/master/heap/meldable_heap.cpp">View this file on GitHub</a>
    - Last commit date: 2019-09-22 22:21:09+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cassert>
#include <cmath>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

//===
//=== xorshift
uint32_t xorshift32() {
    static uint32_t s = 1710;
    s = s ^ (s << 13);
    s = s ^ (s >> 17);
    s = s ^ ( s << 5);
    return s;
}
//===

// not stable
template<typename T, typename Compare = less<T> >
struct MeldableHeap {
    struct Node {
        T dat;
        Node *l, *r;

        Node (T dat): dat(dat), l(nullptr), r(nullptr) {};
    };

    Node *root;
    Compare cmp;

    MeldableHeap (Compare cmp = Compare()): root(nullptr), cmp(cmp) {};

    Node *meld(Node *h1, Node *h2) {
        if (h1 == nullptr) return h2;
        else if (h2 == nullptr) return h1;

        if (cmp(h2->dat, h1->dat)) swap(h1, h2);
        
        if (xorshift32() & 1) h1->l = meld(h1->l, h2);
        else h1->r = meld(h1->r, h2);

        return h1;
    };

    void push(T dat) {
        Node *u = new Node(dat);
        root = meld(root, u);
    };

    T top() { return root->dat; };
    
    T pop() {
        assert(!empty());
        T ret = top();
        Node *rm = root;
        root = meld(root->l, root->r);
        delete rm;
        
        return ret;
    };

    void merge_with(MeldableHeap &h) {
        root = meld(root, h);
        h.root = nullptr;
    };

    bool empty() { return root == nullptr; };
};
// MinHeap<T> = MeldableHeap<T, less<T>>
// MaxHeap<T> = MeldableHeap<T, greater<T>>
//===

int ABC141D() {
    llong n, m;
    llong a;
    MeldableHeap<llong, greater<llong> > h;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a;
        h.push(a);
    }

    for (int i = 0; i < m; i++) {
        a = h.pop() / 2;
        h.push(a);
    }

    llong sum = 0;
    while (!h.empty()) {
        sum += h.pop();
    }

    cout << sum << endl;
    
    return 0;
}

int main() {
    return ABC141D();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "heap/meldable_heap.cpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cassert>
#include <cmath>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using llong = long long;

//===
//=== xorshift
uint32_t xorshift32() {
    static uint32_t s = 1710;
    s = s ^ (s << 13);
    s = s ^ (s >> 17);
    s = s ^ ( s << 5);
    return s;
}
//===

// not stable
template<typename T, typename Compare = less<T> >
struct MeldableHeap {
    struct Node {
        T dat;
        Node *l, *r;

        Node (T dat): dat(dat), l(nullptr), r(nullptr) {};
    };

    Node *root;
    Compare cmp;

    MeldableHeap (Compare cmp = Compare()): root(nullptr), cmp(cmp) {};

    Node *meld(Node *h1, Node *h2) {
        if (h1 == nullptr) return h2;
        else if (h2 == nullptr) return h1;

        if (cmp(h2->dat, h1->dat)) swap(h1, h2);
        
        if (xorshift32() & 1) h1->l = meld(h1->l, h2);
        else h1->r = meld(h1->r, h2);

        return h1;
    };

    void push(T dat) {
        Node *u = new Node(dat);
        root = meld(root, u);
    };

    T top() { return root->dat; };
    
    T pop() {
        assert(!empty());
        T ret = top();
        Node *rm = root;
        root = meld(root->l, root->r);
        delete rm;
        
        return ret;
    };

    void merge_with(MeldableHeap &h) {
        root = meld(root, h);
        h.root = nullptr;
    };

    bool empty() { return root == nullptr; };
};
// MinHeap<T> = MeldableHeap<T, less<T>>
// MaxHeap<T> = MeldableHeap<T, greater<T>>
//===

int ABC141D() {
    llong n, m;
    llong a;
    MeldableHeap<llong, greater<llong> > h;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a;
        h.push(a);
    }

    for (int i = 0; i < m; i++) {
        a = h.pop() / 2;
        h.push(a);
    }

    llong sum = 0;
    while (!h.empty()) {
        sum += h.pop();
    }

    cout << sum << endl;
    
    return 0;
}

int main() {
    return ABC141D();
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


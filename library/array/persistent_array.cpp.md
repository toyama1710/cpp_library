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


# :warning: array/persistent_array.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f1f713c9e000f5d3f280adbd124df4f5">array</a>
* <a href="{{ site.github.repository_url }}/blob/master/array/persistent_array.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-11 17:14:29+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <functional>
#include <vector>
#include <memory>
#include <cstring>
using namespace std;
using llong = long long;

//===
// K-ary tree
template<class T, int K = 2, template<class> class Alloc = allocator>
struct PersistentArray {
    struct Node;
    using Leaf = T;
    struct Node {
        T dat;
        Node* ch[K] = {};

        Node() = default;
        Node(Node *np) {
            dat = np->dat;
            memcpy(ch, np->ch, sizeof(Node *) * K);
        };
    };

    Node *root;
    int arr_size;

    PersistentArray (Node *root, int arr_size):root(root), arr_size(arr_size) {};
    PersistentArray(int size, const T &d = T()):arr_size(size) {
        root = new Node();
        init(root, size, d);
    };
    Node *init(Node *np, int size, T d) {
        np->dat = d;
                             
        if (size == 1) return np;
        for (int i = 0; i < min(K, size); i++) {
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
};
//===


llong n, q;
vector<llong> v;

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        llong a;
        cin >> a;
        v.push_back(a);
    }

    vector<PersistentArray<llong>> r;
    PersistentArray<llong> arr(v.size());
    for (int i = 0; i < arr.size(); i++) {
        arr.destructive_set(i, v[i]);
    }
    r.push_back(arr);

    for (int i = 0; i < q; i++) {
        llong com;
        llong idx, dat;

        cin >> com;
        if (com == 0) {
            cin >> idx >> dat;
            r.push_back(r.back().set(idx, dat));
        }
        else {
            cout << "=====" << endl;
            for (int i = 0; i < r.size(); i++) {
                for (int j = 0; j < r[i].size(); j++) {
                    cout << r[i].get(j) << ' ';
                }
                cout << endl;
            }
            cout << "=====" << endl;
        }
    }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "array/persistent_array.cpp"
#include <iostream>
#include <functional>
#include <vector>
#include <memory>
#include <cstring>
using namespace std;
using llong = long long;

//===
// K-ary tree
template<class T, int K = 2, template<class> class Alloc = allocator>
struct PersistentArray {
    struct Node;
    using Leaf = T;
    struct Node {
        T dat;
        Node* ch[K] = {};

        Node() = default;
        Node(Node *np) {
            dat = np->dat;
            memcpy(ch, np->ch, sizeof(Node *) * K);
        };
    };

    Node *root;
    int arr_size;

    PersistentArray (Node *root, int arr_size):root(root), arr_size(arr_size) {};
    PersistentArray(int size, const T &d = T()):arr_size(size) {
        root = new Node();
        init(root, size, d);
    };
    Node *init(Node *np, int size, T d) {
        np->dat = d;
                             
        if (size == 1) return np;
        for (int i = 0; i < min(K, size); i++) {
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
};
//===


llong n, q;
vector<llong> v;

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        llong a;
        cin >> a;
        v.push_back(a);
    }

    vector<PersistentArray<llong>> r;
    PersistentArray<llong> arr(v.size());
    for (int i = 0; i < arr.size(); i++) {
        arr.destructive_set(i, v[i]);
    }
    r.push_back(arr);

    for (int i = 0; i < q; i++) {
        llong com;
        llong idx, dat;

        cin >> com;
        if (com == 0) {
            cin >> idx >> dat;
            r.push_back(r.back().set(idx, dat));
        }
        else {
            cout << "=====" << endl;
            for (int i = 0; i < r.size(); i++) {
                for (int j = 0; j < r[i].size(); j++) {
                    cout << r[i].get(j) << ' ';
                }
                cout << endl;
            }
            cout << "=====" << endl;
        }
    }

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


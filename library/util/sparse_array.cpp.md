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


# :warning: util/sparse_array.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05c7e24700502a079cdd88012b5a76d3">util</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/sparse_array.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 13:32:31+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define IGNORE
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdint>
#include <array>
using namespace std;
using llong = long long;

//===
// #include <cstdint>
// #include <array>
template<class T, size_t N, size_t BlockSize = 64>
struct SparseArray {
    array<T *, (N + BlockSize - 1) / BlockSize> ptr;

    SparseArray() {
        ptr.fill(nullptr);
    };

    ~SparseArray() {
        clear();
    };

    void clear() {
        for (auto p:ptr) delete p;
        ptr.fill(nullptr);
    };

    T& operator [](size_t k) {
        if (!ptr[k / BlockSize]) ptr[k / BlockSize] = new T[BlockSize];
        return &((ptr[k / BlockSize])[k % BlockSize]);
    };
};
//===

int main() {
    llong n;
    SparseArray<llong, 100> arr;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << ' ';
    }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "util/sparse_array.cpp"
#define IGNORE
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdint>
#include <array>
using namespace std;
using llong = long long;

//===
// #include <cstdint>
// #include <array>
template<class T, size_t N, size_t BlockSize = 64>
struct SparseArray {
    array<T *, (N + BlockSize - 1) / BlockSize> ptr;

    SparseArray() {
        ptr.fill(nullptr);
    };

    ~SparseArray() {
        clear();
    };

    void clear() {
        for (auto p:ptr) delete p;
        ptr.fill(nullptr);
    };

    T& operator [](size_t k) {
        if (!ptr[k / BlockSize]) ptr[k / BlockSize] = new T[BlockSize];
        return &((ptr[k / BlockSize])[k % BlockSize]);
    };
};
//===

int main() {
    llong n;
    SparseArray<llong, 100> arr;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << ' ';
    }

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


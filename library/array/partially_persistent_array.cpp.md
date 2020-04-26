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


# :warning: array/partially_persistent_array.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f1f713c9e000f5d3f280adbd124df4f5">array</a>
* <a href="{{ site.github.repository_url }}/blob/master/array/partially_persistent_array.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-04 22:32:04+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdio>
#include <vector>
#include <iterator>
using namespace std;
using llong = long long;

//===
template <class T>
struct PartiallyPersistentArray {
    int turn;
    vector<vector<pair<int, T>>> arr;
    const size_t sz;

    PartiallyPersistentArray(size_t nmemb, T v): sz(nmemb) {
        turn = 0;
        arr.resize(sz, vector<pair<int, T> >(1, {0, v}));
    };

    template<class InputIterator>
    PartiallyPersistentArray(InputIterator first, InputIterator last):
        sz(distance(first, last))
    {
        turn = 0;
        arr.reserve(sz);
        for (InputIterator i = first; i != last; i++) {
            arr.push_back(vector<pair<int, T>>(1, {0, *i}));
        }
    };

    void set(int k, T v) {
        arr[k].push_back({++turn, v});
    };

    T get(int t, int k) {
        int valid = 0;
        int invalid = arr[k].size();
        int mid;

        while (invalid - valid > 1) {
            mid = (valid + invalid) / 2;

            if (t <= arr[k][mid].first) valid = mid;
            else invalid = mid;
        }

        return arr[k][valid];
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
#line 1 "array/partially_persistent_array.cpp"
#include <iostream>
#include <cstdio>
#include <vector>
#include <iterator>
using namespace std;
using llong = long long;

//===
template <class T>
struct PartiallyPersistentArray {
    int turn;
    vector<vector<pair<int, T>>> arr;
    const size_t sz;

    PartiallyPersistentArray(size_t nmemb, T v): sz(nmemb) {
        turn = 0;
        arr.resize(sz, vector<pair<int, T> >(1, {0, v}));
    };

    template<class InputIterator>
    PartiallyPersistentArray(InputIterator first, InputIterator last):
        sz(distance(first, last))
    {
        turn = 0;
        arr.reserve(sz);
        for (InputIterator i = first; i != last; i++) {
            arr.push_back(vector<pair<int, T>>(1, {0, *i}));
        }
    };

    void set(int k, T v) {
        arr[k].push_back({++turn, v});
    };

    T get(int t, int k) {
        int valid = 0;
        int invalid = arr[k].size();
        int mid;

        while (invalid - valid > 1) {
            mid = (valid + invalid) / 2;

            if (t <= arr[k][mid].first) valid = mid;
            else invalid = mid;
        }

        return arr[k][valid];
    };
};
//===


int main() {

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


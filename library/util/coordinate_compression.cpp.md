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


# :warning: util/coordinate_compression.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05c7e24700502a079cdd88012b5a76d3">util</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/coordinate_compression.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-15 02:56:32+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// header file section
#include <iostream>
#include <cstdio>
#include <cfloat>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <algorithm>
#include <iterator>

using namespace std;
using llong = long long;

//===
// library section
// <iterator>
struct CoordinateCompression {
    vector<llong> p;

    CoordinateCompression () {};
    template <class InputItr>
    CoordinateCompression (InputItr first, InputItr last) {
        p.reserve(distance(first, last));
        for (auto itr = first; itr != last; itr++) {
            p.push_back(*itr);
        }
        build();
    };

    void build() {
        sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());
    };

    void add(llong a) {
        p.push_back(a);
    };

    llong zip(llong x) {
        return lower_bound(p.begin(), p.end(), x) - p.begin();
    };
    llong unzip(llong x) {
        return p[x];
    };

    llong size() {
        return p.size();
    };
};
//===

int main() {
    return 0;
};


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "util/coordinate_compression.cpp"
// header file section
#include <iostream>
#include <cstdio>
#include <cfloat>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <algorithm>
#include <iterator>

using namespace std;
using llong = long long;

//===
// library section
// <iterator>
struct CoordinateCompression {
    vector<llong> p;

    CoordinateCompression () {};
    template <class InputItr>
    CoordinateCompression (InputItr first, InputItr last) {
        p.reserve(distance(first, last));
        for (auto itr = first; itr != last; itr++) {
            p.push_back(*itr);
        }
        build();
    };

    void build() {
        sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());
    };

    void add(llong a) {
        p.push_back(a);
    };

    llong zip(llong x) {
        return lower_bound(p.begin(), p.end(), x) - p.begin();
    };
    llong unzip(llong x) {
        return p[x];
    };

    llong size() {
        return p.size();
    };
};
//===

int main() {
    return 0;
};


```
{% endraw %}

<a href="../../index.html">Back to top page</a>


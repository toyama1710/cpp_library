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


# :x: util/coordinate_compression.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05c7e24700502a079cdd88012b5a76d3">util</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/coordinate_compression.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-30 19:16:59+00:00




## Verified with

* :x: <a href="../../verify/test/yosupo/rectangle_sum1.test.cpp.html">test/yosupo/rectangle_sum1.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// header file section
#include <vector>
#include <iterator>
#include <algorithm>
#include <cassert>

//===
// library section
// <iterator>
struct CoordinateCompression {
    using llong = long long;
    std::vector<llong> p;

#ifndef NODEBUG
    bool builded = false;
#endif

    CoordinateCompression () {};
    template <class InputItr>
    CoordinateCompression (InputItr first, InputItr last) {
        p.reserve(std::distance(first, last));
        for (auto itr = first; itr != last; itr++) {
            p.push_back(*itr);
        }
        build();
    };

    void build() {
        std::sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());
#ifndef NODEBUG
        builded = true;
#endif
    };

    void add(llong a) {
        p.push_back(a);
#ifndef NODEBUG
        builded = false;
#endif
    };
    void push(llong a) {
        add(a);
    }

    llong zip(llong x) {
#ifndef NODEBUG
        assert(builded);
#endif
        return std::lower_bound(p.begin(), p.end(), x) - p.begin();
    };
    llong unzip(llong x) {
#ifndef NODEBUG
        assert(builded);
#endif
        return p[x];
    };

    llong size() {
        return p.size();
    };
};
//===

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "util/coordinate_compression.hpp"
// header file section
#include <vector>
#include <iterator>
#include <algorithm>
#include <cassert>

//===
// library section
// <iterator>
struct CoordinateCompression {
    using llong = long long;
    std::vector<llong> p;

#ifndef NODEBUG
    bool builded = false;
#endif

    CoordinateCompression () {};
    template <class InputItr>
    CoordinateCompression (InputItr first, InputItr last) {
        p.reserve(std::distance(first, last));
        for (auto itr = first; itr != last; itr++) {
            p.push_back(*itr);
        }
        build();
    };

    void build() {
        std::sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());
#ifndef NODEBUG
        builded = true;
#endif
    };

    void add(llong a) {
        p.push_back(a);
#ifndef NODEBUG
        builded = false;
#endif
    };
    void push(llong a) {
        add(a);
    }

    llong zip(llong x) {
#ifndef NODEBUG
        assert(builded);
#endif
        return std::lower_bound(p.begin(), p.end(), x) - p.begin();
    };
    llong unzip(llong x) {
#ifndef NODEBUG
        assert(builded);
#endif
        return p[x];
    };

    llong size() {
        return p.size();
    };
};
//===

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


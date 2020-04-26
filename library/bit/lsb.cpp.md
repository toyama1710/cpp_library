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


# :warning: bit/lsb.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f67169dfbf72c4ca285e9ee12e3e9ac5">bit</a>
* <a href="{{ site.github.repository_url }}/blob/master/bit/lsb.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-15 21:16:02+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdio>
using namespace std;
using llong = long long;

//===
template<class Integer>
inline Integer lsb(Integer bits) {
    return bits & (~bits + 1);
}
//===

int main() {
    int a;
    llong b;
    unsigned c;

    cin >> a >> b >> c;
    cout << lsb(a) << ' ' << lsb(b) << ' ' << lsb(c) << endl;

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "bit/lsb.cpp"
#include <iostream>
#include <cstdio>
using namespace std;
using llong = long long;

//===
template<class Integer>
inline Integer lsb(Integer bits) {
    return bits & (~bits + 1);
}
//===

int main() {
    int a;
    llong b;
    unsigned c;

    cin >> a >> b >> c;
    cout << lsb(a) << ' ' << lsb(b) << ' ' << lsb(c) << endl;

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


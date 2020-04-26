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


# :warning: util/xorshift.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05c7e24700502a079cdd88012b5a76d3">util</a>
* <a href="{{ site.github.repository_url }}/blob/master/util/xorshift.cpp">View this file on GitHub</a>
    - Last commit date: 2019-09-27 22:25:24+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdint>
#include <ctime>
using namespace std;

//===
uint32_t xorshift32() {
    static uint32_t s = 1710;
    s = s ^ (s << 13);
    s = s ^ (s >> 17);
    s = s ^ ( s << 5);
    return s;
}
//===

int main() {
    uint32_t n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << xorshift32() << endl;
    }

    return 0;
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "util/xorshift.cpp"
#include <iostream>
#include <cstdint>
#include <ctime>
using namespace std;

//===
uint32_t xorshift32() {
    static uint32_t s = 1710;
    s = s ^ (s << 13);
    s = s ^ (s >> 17);
    s = s ^ ( s << 5);
    return s;
}
//===

int main() {
    uint32_t n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << xorshift32() << endl;
    }

    return 0;
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


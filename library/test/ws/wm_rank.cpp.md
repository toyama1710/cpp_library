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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: test/ws/wm_rank.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#371cfd9101dedf155cc0c947ec787865">test/ws</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/ws/wm_rank.cpp">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdint>
#include <ctime>
#include <vector>
#include <cassert>
#include "../../compact_data_structure/bit_vector.hpp"
#include "../../wavelet_tree/wavelet_matrix.hpp"
#include "../../util/xorshift.hpp"
using namespace std;

int n;
vector<unsigned int> v;

int main() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        v[i] = xorshift32() % 128;
    }

    WaveletMatrix<unsigned int, 16, BitVector> wm(v);

    for (int i = 0; i < n * n; i++) {
        int k = xorshift32() % n;
        int x = v[(xorshift32()) % n];

        int cnt = 0;
        for (int i = 0; i < k; i++) if (v[i] == x) cnt++;

        if (cnt != wm.rank(x, k)) {
            cout << x << ' ' << k << ':' << "test failed" << endl;
            cout << cnt << ' ' << wm.rank(x, k) << endl;
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 307, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 187, in _resolve
    raise BundleErrorAt(path, -1, "no such header")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../wavelet_tree/wavelet_matrix.hpp: line -1: no such header

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>


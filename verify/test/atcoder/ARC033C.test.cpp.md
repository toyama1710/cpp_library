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


# :x: test/atcoder/ARC033C.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e8ba03245cc911ba95395348d53122a0">test/atcoder</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/atcoder/ARC033C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-09 07:02:40+00:00




## Depends on

* :question: <a href="../../../library/data_type/sum_monoid.hpp.html">data_type/sum_monoid.hpp</a>
* :question: <a href="../../../library/segment_tree/segment_tree.hpp.html">segment_tree/segment_tree.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc033/tasks/arc033_3"
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
#include "../../segment_tree/segment_tree.hpp"
#include "../../data_type/sum_monoid.hpp"

using namespace std;
using llong = long long;

int q;
int t, x;
const int n = 200001;
SegmentTree<SumMonoid<llong>> st(n);

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> q;
    while (q--) {
        cin >> t >> x;

        if (t == 1) {
            st.update(x, st[x] + 1);
        }
        else {
            int idx = st.bsearch(0, n, x,
                    [&](llong sum){
                        return sum >= x;
                    });
            st.update(idx, st[idx] - 1);
            cout << idx << '\n';
        }
    }

    return 0;
};


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/atcoder/ARC033C.test.cpp"
#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc033/tasks/arc033_3"
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
#line 1 "segment_tree/segment_tree.hpp"



#line 6 "segment_tree/segment_tree.hpp"
#include <iterator>

//===
template<class Monoid>
struct SegmentTree {
    using T = typename Monoid::value_type;

    std::vector<T> tree;

    SegmentTree() = default;
    explicit SegmentTree(int n)
        :tree(n << 1, Monoid::identity()) {};

    template<class InputIterator>
    SegmentTree(InputIterator first, InputIterator last) {
        tree.assign(distance(first, last) << 1, Monoid::identity());

        int i;
        i = size();
        for (InputIterator itr = first; itr != last; itr++) {
            tree[i++] = *itr;
        }
        for (i = size() - 1; i > 0; i--) {
            tree[i] = Monoid::operation(tree[(i << 1)], tree[(i << 1) | 1]);
        }
    };

    inline int size() {
        return tree.size() >> 1;
    };

    inline T operator[] (int k) {
        return tree[k + size()];
    };

    void update(int k, const T dat) {
        k += size();
        tree[k] = dat;
        
        while(k > 1) {
            k >>= 1;
            tree[k] = Monoid::operation(tree[(k << 1)], tree[(k << 1) | 1]);
        }
    };

    // [l, r)
    T fold(int l, int r) {
        l += size(); //points leaf
        r += size();

        T lv = Monoid::identity();
        T rv = Monoid::identity();
        while (l < r) {
            if (l & 1) lv = Monoid::operation(lv, tree[l++]);
            if (r & 1) rv = Monoid::operation(tree[--r], rv);
            l >>= 1;
            r >>= 1;
        }

        return Monoid::operation(lv, rv);
    };

    template<class F>
    int bsearch(int l, int r, T s, F f) {
        l += size();
        r += size();
        std::vector<int> left, right;
        std::vector<int> q_idx;
        while (l < r) {
            if (l & 1) left.push_back(l++);
            if (r & 1) right.push_back(--r);
            l >>= 1;
            r >>= 1;
        }
        std::swap(q_idx, left);
        for (auto itr = right.rbegin(); itr != right.rend(); itr++) q_idx.push_back(*itr);

        T sum = Monoid::identity();
        for (auto v:q_idx) {
            if (f(Monoid::operation(sum, tree[v]))) {
                int i = v;
                while (i < size()) {
                    if (f(Monoid::operation(sum, tree[i << 1]))) {
                        i = i << 1;
                    }
                    else {
                        sum = Monoid::operation(sum, tree[i << 1]);
                        i = (i << 1) | 1;
                    }
                }
                return i - size();
            }
            else {
                sum = Monoid::operation(sum, tree[v]);
            }
        }
        return -1;
    };
};
//===


#line 1 "data_type/sum_monoid.hpp"



template<class T>
struct SumMonoid {
    using value_type = T;
    inline static T identity() {
        return (T)0;
    };
    inline static T operation(const T a, const T b) {
        return a + b;
    };
};


#line 18 "test/atcoder/ARC033C.test.cpp"

using namespace std;
using llong = long long;

int q;
int t, x;
const int n = 200001;
SegmentTree<SumMonoid<llong>> st(n);

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> q;
    while (q--) {
        cin >> t >> x;

        if (t == 1) {
            st.update(x, st[x] + 1);
        }
        else {
            int idx = st.bsearch(0, n, x,
                    [&](llong sum){
                        return sum >= x;
                    });
            st.update(idx, st[idx] - 1);
            cout << idx << '\n';
        }
    }

    return 0;
};


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>


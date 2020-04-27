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


# :heavy_check_mark: test/yosupo/queue_aggregation.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/queue_aggregation.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 16:50:39+09:00


* see: <a href="https://judge.yosupo.jp/problem/queue_operate_all_composite">https://judge.yosupo.jp/problem/queue_operate_all_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/queue/queue_aggregation.hpp.html">queue/queue_aggregation.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
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
#include "../../queue/queue_aggregation.hpp"

using namespace std;
using llong = long long;

//const llong mod = 998244353;
#define mod (998244353ll)
QueueAggregation<pair<llong, llong>> swag([](auto l, auto r) {
            pair<llong, llong> ret;
            ret.first = r.first * l.first;
            ret.second = r.first * l.second + r.second;
            ret.first %= mod;
            ret.second %= mod;
            return ret;
        });

int main() {
    llong q;
    llong com;
    llong a, b;
    llong x;

    cin >> q;

    while (q--) {
        cin >> com;

        if (com == 0) {
            cin >> a >> b;
            swag.push({a, b});
        }
        else if (com == 1) {
            swag.pop();
        }
        else if (com == 2) {
            cin >> x;

            if (swag.empty()) {
                cout << x << '\n';
            }
            else {
                auto f = swag.fold();
                cout << (f.first * x + f.second) % mod << '\n';
            }
        }
    }
    return 0;
};


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/queue_aggregation.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
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
#line 3 "queue/queue_aggregation.hpp"
#include <cassert>
#line 6 "queue/queue_aggregation.hpp"

//===
// LIBRARY SECTION

// #include <stack>
// #include <cassert>
template<class SemiGroup, class OP = std::function<SemiGroup(SemiGroup, SemiGroup)> >
struct QueueAggregation {
    using Stack = std::stack<std::pair<SemiGroup, SemiGroup>>;
    const OP merge;
    Stack front_st, back_st;

    QueueAggregation(const OP &f):merge(f) {};

    SemiGroup fold() {
        assert(!empty());
        
        if (front_st.empty()) return back_st.top().second;
        else if (back_st.empty()) return front_st.top().second;
        else return merge(front_st.top().second, back_st.top().second);
    };

    void push(SemiGroup d) {
        if (back_st.empty()) back_st.emplace(d, d);
        else back_st.emplace(d, merge(back_st.top().second, d));
    };

    void pop() {
        assert(!empty());

        if (front_st.empty()) {
            front_st.emplace(back_st.top().first, back_st.top().first);
            back_st.pop();
            
            while (!back_st.empty()) {
                front_st.emplace(back_st.top().first, merge(back_st.top().first, front_st.top().second));
                back_st.pop();
            }
        }
        
        front_st.pop();
    };

    bool empty() {
        return size() == 0;
    };

    size_t size() {
        return front_st.size() + back_st.size();
    };
};
//===
#line 16 "test/yosupo/queue_aggregation.test.cpp"

using namespace std;
using llong = long long;

//const llong mod = 998244353;
#define mod (998244353ll)
QueueAggregation<pair<llong, llong>> swag([](auto l, auto r) {
            pair<llong, llong> ret;
            ret.first = r.first * l.first;
            ret.second = r.first * l.second + r.second;
            ret.first %= mod;
            ret.second %= mod;
            return ret;
        });

int main() {
    llong q;
    llong com;
    llong a, b;
    llong x;

    cin >> q;

    while (q--) {
        cin >> com;

        if (com == 0) {
            cin >> a >> b;
            swag.push({a, b});
        }
        else if (com == 1) {
            swag.pop();
        }
        else if (com == 2) {
            cin >> x;

            if (swag.empty()) {
                cout << x << '\n';
            }
            else {
                auto f = swag.fold();
                cout << (f.first * x + f.second) % mod << '\n';
            }
        }
    }
    return 0;
};


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>


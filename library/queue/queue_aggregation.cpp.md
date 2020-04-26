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


# :warning: queue/queue_aggregation.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a9d1cbf71942327e98b40cf5ef38a960">queue</a>
* <a href="{{ site.github.repository_url }}/blob/master/queue/queue_aggregation.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-10 20:40:03+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdio>
#include <cassert>
#include <functional>
#include <stack>
using namespace std;
using llong = long long;

//===
// #include <stack>
// #include <cassert>
template<class SemiGroup, class OP = function<SemiGroup(SemiGroup, SemiGroup)> >
struct QueueAggregation {
    using Stack = stack<SemiGroup>;
    const OP merge;
    Stack front_st, back_st;
    Stack front_sum, back_sum;
    size_t sz;

    QueueAggregation(const OP &f):merge(f) {
        sz = 0;
    };

    SemiGroup fold() {
        assert(sz > 0);
        
        if (front_sum.empty()) return back_sum.top();
        else if (back_sum.empty()) return front_sum.top();
        else return merge(front_sum.top(), back_sum.top());
    };

    void push(SemiGroup d) {
        sz++;
        back_st.push(d);
        if (back_sum.empty()) back_sum.push(d);
        else back_sum.push(merge(back_sum.top(), d));
    };

    void pop() {
        assert(sz > 0);

        sz--;
        if (front_st.empty()) {
            front_st.push(back_st.top());
            front_sum.push(back_st.top());
            back_st.pop();
            back_sum.pop();
            
            while (!back_st.empty()) {
                front_st.push(back_st.top());
                front_sum.push(merge(front_sum.top(), back_st.top()));
                back_st.pop();
                back_sum.pop();
            }
        }
        
        front_st.pop();
        front_sum.pop();
    };

    bool empty() {
        return sz == 0;
    };

    size_t size() {
        return sz;
    };
};
//===

int AOJ_DSL3D() {
    llong n;
    llong l;
    static llong arr[1000005];
    
    QueueAggregation<llong> smin([](auto l, auto r){return min(l, r);});

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < l; i++) {
        smin.push(arr[i]);
    }

    cout << smin.fold();
    for (int i = l; i < n; i++) {
        smin.pop();
        smin.push(arr[i]);

        cout << ' ' << smin.fold();
    }
    cout << endl;

    return 0;
}

int main() {
    return AOJ_DSL3D();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "queue/queue_aggregation.cpp"
#include <iostream>
#include <cstdio>
#include <cassert>
#include <functional>
#include <stack>
using namespace std;
using llong = long long;

//===
// #include <stack>
// #include <cassert>
template<class SemiGroup, class OP = function<SemiGroup(SemiGroup, SemiGroup)> >
struct QueueAggregation {
    using Stack = stack<SemiGroup>;
    const OP merge;
    Stack front_st, back_st;
    Stack front_sum, back_sum;
    size_t sz;

    QueueAggregation(const OP &f):merge(f) {
        sz = 0;
    };

    SemiGroup fold() {
        assert(sz > 0);
        
        if (front_sum.empty()) return back_sum.top();
        else if (back_sum.empty()) return front_sum.top();
        else return merge(front_sum.top(), back_sum.top());
    };

    void push(SemiGroup d) {
        sz++;
        back_st.push(d);
        if (back_sum.empty()) back_sum.push(d);
        else back_sum.push(merge(back_sum.top(), d));
    };

    void pop() {
        assert(sz > 0);

        sz--;
        if (front_st.empty()) {
            front_st.push(back_st.top());
            front_sum.push(back_st.top());
            back_st.pop();
            back_sum.pop();
            
            while (!back_st.empty()) {
                front_st.push(back_st.top());
                front_sum.push(merge(front_sum.top(), back_st.top()));
                back_st.pop();
                back_sum.pop();
            }
        }
        
        front_st.pop();
        front_sum.pop();
    };

    bool empty() {
        return sz == 0;
    };

    size_t size() {
        return sz;
    };
};
//===

int AOJ_DSL3D() {
    llong n;
    llong l;
    static llong arr[1000005];
    
    QueueAggregation<llong> smin([](auto l, auto r){return min(l, r);});

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < l; i++) {
        smin.push(arr[i]);
    }

    cout << smin.fold();
    for (int i = l; i < n; i++) {
        smin.pop();
        smin.push(arr[i]);

        cout << ' ' << smin.fold();
    }
    cout << endl;

    return 0;
}

int main() {
    return AOJ_DSL3D();
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


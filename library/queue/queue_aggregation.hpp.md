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


# :x: queue/queue_aggregation.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a9d1cbf71942327e98b40cf5ef38a960">queue</a>
* <a href="{{ site.github.repository_url }}/blob/master/queue/queue_aggregation.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 03:08:13+00:00




## Verified with

* :x: <a href="../../verify/test/yosupo/queue_aggregation.test.cpp.html">test/yosupo/queue_aggregation.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdio>
#include <cassert>
#include <functional>
#include <stack>

//===
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
                front_st.emplace(back_st.top().first, merge(front_st.top().second, back_st.top().first));
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "queue/queue_aggregation.hpp"
#include <iostream>
#include <cstdio>
#include <cassert>
#include <functional>
#include <stack>

//===
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
                front_st.emplace(back_st.top().first, merge(front_st.top().second, back_st.top().first));
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


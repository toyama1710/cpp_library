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


# :heavy_check_mark: deque/sliding_window.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#eb30267afe2f60536940ebb01df616b5">deque</a>
* <a href="{{ site.github.repository_url }}/blob/master/deque/sliding_window.hpp">View this file on GitHub</a>
    - Last commit date: 2020-04-27 02:36:21+00:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/swag.test.cpp.html">test/yosupo/swag.test.cpp</a>


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
struct SlidingWindow {
    // first:original data, second:sum
    using Stack = std::stack<std::pair<SemiGroup, SemiGroup> >;
    const OP merge;

    Stack front_st, back_st;

    SlidingWindow(const OP &f):merge(f) {};

    inline SemiGroup fold() {
        assert(!empty());
        
        if (front_st.empty()) return back_st.top().second;
        else if (back_st.empty()) return front_st.top().second;
        else return merge(front_st.top().second, back_st.top().second);
    };

    inline void push_front(SemiGroup d) {
        if (front_st.empty()) front_st.emplace(d, d);
        else front_st.emplace(d, merge(d, front_st.top().second));
    };
    inline void push_back(SemiGroup d) {
        if (back_st.empty()) back_st.emplace(d, d);
        else back_st.emplace(d, merge(back_st.top().second, d));
    };

    void pop_front() {
        assert(!empty());

        if (front_st.empty()) {
            Stack buff;
            while (buff.size() + 1 < back_st.size()) {
                buff.push(back_st.top());
                back_st.pop();
            }
            while (!back_st.empty()) {
                push_front(back_st.top().first);
                back_st.pop();
            }
            while (!buff.empty()) {
                push_back(buff.top().first);
                buff.pop();
            }
        }
        front_st.pop();
    };
    void pop_back() {
        assert(!empty());

        if (back_st.empty()) {
            Stack buff;
            while (buff.size() + 1 < front_st.size()) {
                buff.push(front_st.top());
                front_st.pop();
            }
            while (!front_st.empty()) {
                push_back(front_st.top().first);
                front_st.pop();
            }
            while (!buff.empty()) {
                push_front(buff.top().first);
                buff.pop();
            }
        }
        back_st.pop();
    };
    
    inline bool empty() {
        return size() == 0;
    };

    inline size_t size() {
        return front_st.size() + back_st.size();
    };
};
//===

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "deque/sliding_window.hpp"
#include <iostream>
#include <cstdio>
#include <cassert>
#include <functional>
#include <stack>

//===
// #include <stack>
// #include <cassert>
template<class SemiGroup, class OP = std::function<SemiGroup(SemiGroup, SemiGroup)> >
struct SlidingWindow {
    // first:original data, second:sum
    using Stack = std::stack<std::pair<SemiGroup, SemiGroup> >;
    const OP merge;

    Stack front_st, back_st;

    SlidingWindow(const OP &f):merge(f) {};

    inline SemiGroup fold() {
        assert(!empty());
        
        if (front_st.empty()) return back_st.top().second;
        else if (back_st.empty()) return front_st.top().second;
        else return merge(front_st.top().second, back_st.top().second);
    };

    inline void push_front(SemiGroup d) {
        if (front_st.empty()) front_st.emplace(d, d);
        else front_st.emplace(d, merge(d, front_st.top().second));
    };
    inline void push_back(SemiGroup d) {
        if (back_st.empty()) back_st.emplace(d, d);
        else back_st.emplace(d, merge(back_st.top().second, d));
    };

    void pop_front() {
        assert(!empty());

        if (front_st.empty()) {
            Stack buff;
            while (buff.size() + 1 < back_st.size()) {
                buff.push(back_st.top());
                back_st.pop();
            }
            while (!back_st.empty()) {
                push_front(back_st.top().first);
                back_st.pop();
            }
            while (!buff.empty()) {
                push_back(buff.top().first);
                buff.pop();
            }
        }
        front_st.pop();
    };
    void pop_back() {
        assert(!empty());

        if (back_st.empty()) {
            Stack buff;
            while (buff.size() + 1 < front_st.size()) {
                buff.push(front_st.top());
                front_st.pop();
            }
            while (!front_st.empty()) {
                push_back(front_st.top().first);
                front_st.pop();
            }
            while (!buff.empty()) {
                push_front(buff.top().first);
                buff.pop();
            }
        }
        back_st.pop();
    };
    
    inline bool empty() {
        return size() == 0;
    };

    inline size_t size() {
        return front_st.size() + back_st.size();
    };
};
//===

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


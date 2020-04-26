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


# :warning: deque/sliding_window.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#eb30267afe2f60536940ebb01df616b5">deque</a>
* <a href="{{ site.github.repository_url }}/blob/master/deque/sliding_window.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-10 23:00:11+09:00




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
struct SlidingWindow {
    using Stack = stack<pair<SemiGroup, SemiGroup> >;
    const OP merge;

    Stack front_st, back_st;
    size_t sz;

    SlidingWindow(const OP &f):merge(f) {
        sz = 0;
    };

    SemiGroup fold() {
        assert(sz > 0);
        
        if (front_st.empty()) return back_st.top().second;
        else if (back_st.empty()) return front_st.top().second;
        else return merge(front_st.top().second, back_st.top().second);
    };

    void push(SemiGroup d, Stack &front_stack, Stack &back_stack) {
        sz++;
        if (back_stack.empty()) back_stack.push({d, d});
        else back_stack.push({d, merge(back_stack.top().second, d)});
    };

    void pop(Stack &front_stack, Stack &back_stack) {
        assert(!empty());
        sz--;
        
        if (front_stack.empty()) {
            Stack buff;

            while (buff.size() + 1 < back_stack.size()) {
                buff.push(back_stack.top());
                back_stack.pop();
            }

            while (!back_stack.empty()) {
                if (front_stack.empty()) front_stack.push({back_stack.top().first,
                                                           back_stack.top().first});
                else front_stack.push({back_stack.top().first,
                                       merge(back_stack.top().first, front_stack.top().second)});
                back_stack.pop();
            }
            
            while (!buff.empty()) {
                if (back_stack.empty()) back_stack.push({buff.top().first,
                                                         buff.top().first});
                else back_stack.push({buff.top().first,
                                      merge(back_stack.top().second, buff.top().first)});
                buff.pop();
            }
        }
        front_stack.pop();
    };

    void push_front(SemiGroup d) {
        push(d, back_st, front_st);
    };
    void push_back(SemiGroup d) {
        push(d, front_st, back_st);
    };

    void pop_front() {
        pop(front_st, back_st);
    };
    void pop_back() {
        pop(back_st, front_st);
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
    
    SlidingWindow<llong> smin([](auto l, auto r){return min(l, r);});

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < l; i++) {
        smin.push_back(arr[i]);
    }

    cout << smin.fold();
    for (int i = l; i < n; i++) {
        smin.pop_front();
        smin.push_back(arr[i]);

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
#line 1 "deque/sliding_window.cpp"
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
struct SlidingWindow {
    using Stack = stack<pair<SemiGroup, SemiGroup> >;
    const OP merge;

    Stack front_st, back_st;
    size_t sz;

    SlidingWindow(const OP &f):merge(f) {
        sz = 0;
    };

    SemiGroup fold() {
        assert(sz > 0);
        
        if (front_st.empty()) return back_st.top().second;
        else if (back_st.empty()) return front_st.top().second;
        else return merge(front_st.top().second, back_st.top().second);
    };

    void push(SemiGroup d, Stack &front_stack, Stack &back_stack) {
        sz++;
        if (back_stack.empty()) back_stack.push({d, d});
        else back_stack.push({d, merge(back_stack.top().second, d)});
    };

    void pop(Stack &front_stack, Stack &back_stack) {
        assert(!empty());
        sz--;
        
        if (front_stack.empty()) {
            Stack buff;

            while (buff.size() + 1 < back_stack.size()) {
                buff.push(back_stack.top());
                back_stack.pop();
            }

            while (!back_stack.empty()) {
                if (front_stack.empty()) front_stack.push({back_stack.top().first,
                                                           back_stack.top().first});
                else front_stack.push({back_stack.top().first,
                                       merge(back_stack.top().first, front_stack.top().second)});
                back_stack.pop();
            }
            
            while (!buff.empty()) {
                if (back_stack.empty()) back_stack.push({buff.top().first,
                                                         buff.top().first});
                else back_stack.push({buff.top().first,
                                      merge(back_stack.top().second, buff.top().first)});
                buff.pop();
            }
        }
        front_stack.pop();
    };

    void push_front(SemiGroup d) {
        push(d, back_st, front_st);
    };
    void push_back(SemiGroup d) {
        push(d, front_st, back_st);
    };

    void pop_front() {
        pop(front_st, back_st);
    };
    void pop_back() {
        pop(back_st, front_st);
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
    
    SlidingWindow<llong> smin([](auto l, auto r){return min(l, r);});

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < l; i++) {
        smin.push_back(arr[i]);
    }

    cout << smin.fold();
    for (int i = l; i < n; i++) {
        smin.pop_front();
        smin.push_back(arr[i]);

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


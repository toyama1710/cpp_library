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


# :warning: heap/find_kth.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4d4a9aa362b6ffe089fd2e992ccf4f5f">heap</a>
* <a href="{{ site.github.repository_url }}/blob/master/heap/find_kth.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-31 22:26:36+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define NODEBUG
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cassert>
using namespace std;
using llong = long long;

//===
//#include <cassert>
template<class T, class Compare = function<bool(T, T)>,
         class Heap = priority_queue<T, vector<T>, Compare> >
struct FindKth {
    const int K;
    Heap maxh;
    Heap minh;

    FindKth (const int K, const Compare &cmp = less<T>()):
        K(K),
        maxh(cmp),
        minh([cmp](auto l, auto r){ return cmp(r, l); })
    {};
    
    size_t size() {
        return maxh.size() + minh.size();
    };
    bool empty() {
        return size() <= 0;
    };

    void push(T d){
        maxh.push(d);
        if (maxh.size() > K) {
            minh.push(maxh.top());
            maxh.pop();
        }
    };
    
    T find(){
        assert(maxh.size() == K);
        return maxh.top();
    };
    T find_lower(){
        assert(!empty());
        return maxh.top();
    };
    
    void pop() {
        assert(!empty());

        maxh.pop();
        if (!minh.empty()) {
            maxh.push(minh.top());
            minh.pop();
        }
    };
};
//===

int yc649() {
    
    llong q, k;
    llong com, v;

    cin >> q >> k;
    FindKth<llong> st(k);

    while (q--) {
        cin >> com;

        if (com == 1) {
            cin >> v;
            st.push(v);
        }
        else {
            if (st.size() < k) {
                cout << -1 << endl;
            }
            else {
                cout << st.find() << endl;
                st.pop();
            }
        }
    }
    
    return 0;
}

int main() {
    return yc649();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "heap/find_kth.cpp"
#define NODEBUG
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cassert>
using namespace std;
using llong = long long;

//===
//#include <cassert>
template<class T, class Compare = function<bool(T, T)>,
         class Heap = priority_queue<T, vector<T>, Compare> >
struct FindKth {
    const int K;
    Heap maxh;
    Heap minh;

    FindKth (const int K, const Compare &cmp = less<T>()):
        K(K),
        maxh(cmp),
        minh([cmp](auto l, auto r){ return cmp(r, l); })
    {};
    
    size_t size() {
        return maxh.size() + minh.size();
    };
    bool empty() {
        return size() <= 0;
    };

    void push(T d){
        maxh.push(d);
        if (maxh.size() > K) {
            minh.push(maxh.top());
            maxh.pop();
        }
    };
    
    T find(){
        assert(maxh.size() == K);
        return maxh.top();
    };
    T find_lower(){
        assert(!empty());
        return maxh.top();
    };
    
    void pop() {
        assert(!empty());

        maxh.pop();
        if (!minh.empty()) {
            maxh.push(minh.top());
            minh.pop();
        }
    };
};
//===

int yc649() {
    
    llong q, k;
    llong com, v;

    cin >> q >> k;
    FindKth<llong> st(k);

    while (q--) {
        cin >> com;

        if (com == 1) {
            cin >> v;
            st.push(v);
        }
        else {
            if (st.size() < k) {
                cout << -1 << endl;
            }
            else {
                cout << st.find() << endl;
                st.pop();
            }
        }
    }
    
    return 0;
}

int main() {
    return yc649();
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


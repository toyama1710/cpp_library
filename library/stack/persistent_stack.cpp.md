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


# :warning: stack/persistent_stack.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#fac2a47adace059aff113283a03f6760">stack</a>
* <a href="{{ site.github.repository_url }}/blob/master/stack/persistent_stack.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-07 23:52:44+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <memory>
using namespace std;
using llong = long long;

//===
template<class T, template<class> class Alloc = allocator>
struct PersistentStack {
    struct Node {
        T d;
        Node *next = nullptr;
    };
    using Traits = allocator_traits<Alloc<Node> >;
    static Alloc<Node> alc;

    Node *head = nullptr;

    PersistentStack current_stack() {
        return PersistentStack(head);
    };

    T top() {
        return head->d;
    };

    void push(T d) {
        Node *p = Traits::allocate(alc, 1);
        Traits::construct(alc, p, d, head);
        head = p;
    };

    void pop(T d) {
        head = head->next;
    };

    ~PersistentStack() {
        Node *p;
        while (head != nullptr) {
            p = head->next;
            Traits::deallocate(alc, head, 1);
            head = p;
        }
    };
};
//===

int main() {

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "stack/persistent_stack.cpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <memory>
using namespace std;
using llong = long long;

//===
template<class T, template<class> class Alloc = allocator>
struct PersistentStack {
    struct Node {
        T d;
        Node *next = nullptr;
    };
    using Traits = allocator_traits<Alloc<Node> >;
    static Alloc<Node> alc;

    Node *head = nullptr;

    PersistentStack current_stack() {
        return PersistentStack(head);
    };

    T top() {
        return head->d;
    };

    void push(T d) {
        Node *p = Traits::allocate(alc, 1);
        Traits::construct(alc, p, d, head);
        head = p;
    };

    void pop(T d) {
        head = head->next;
    };

    ~PersistentStack() {
        Node *p;
        while (head != nullptr) {
            p = head->next;
            Traits::deallocate(alc, head, 1);
            head = p;
        }
    };
};
//===

int main() {

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>


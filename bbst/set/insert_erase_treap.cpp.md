---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"bbst/set/insert_erase_treap.cpp\"\n\n\n\n#include <iostream>\n\
    #include <cstdint>\n#include <random>\n#include <functional>\n#include <cassert>\n\
    #include <memory>\nusing namespace std;\nusing ll = long long;\n\n//===\ntemplate\
    \ <class T, class Compare = less<T>,\n          template<class> class Alloc =\
    \ allocator>\nstruct Treap {\n    using uint = uint_fast32_t;\n    using uint64\
    \ = uint_fast64_t;\n    \n    struct Node {\n        T dat;\n        uint64 p;\n\
    \n        uint sz = 1;\n        Node *parent;\n        Node *left;\n        Node\
    \ *right;\n\n        Node(T dat, uint64 p):\n            dat(dat), p(p), parent(nullptr),\
    \ left(nullptr), right(nullptr) {}\n    };\n    \n    Node *root;\n    const Compare\
    \ cmp;\n    mt19937 rnd;\n    \n    Alloc<Node> alc;\n    using Traits = allocator_traits<Alloc<Node>\
    \ >;\n    \n    Treap(const Compare &cmp = Compare()):\n        root(nullptr),\
    \ cmp(cmp), rnd(mt19937(random_device()())) {};\n    \n    void clear(Node *u)\
    \ {\n        if (u == nullptr) return;\n        clear(u->left);\n        clear(u->right);\n\
    \        Traits::deallocate(alc, u, 1);\n    };\n    ~Treap() {\n        clear(root);\n\
    \    };\n    \n    bool has_element(T x) {\n        Node *w = root;\n\n      \
    \  while (w != nullptr) {\n            bool c1 = cmp(w->dat, x);\n           \
    \ bool c2 = cmp(x, w->dat);\n            \n            if (c1) w = w->right;\n\
    \            else if (c2) w = w->left;\n            else return true;\n      \
    \  }\n        return false;\n    };\n    \n    uint size(Node *r) {\n        return\
    \ r == nullptr ? 0 : r->sz;\n    };\n    uint size() {\n        return size(root);\n\
    \    };\n    uint calc_size(Node *r) {\n        r->sz = size(r->left) + size(r->right)\
    \ + 1;\n        return r->sz;\n    };\n    void upward_calc_size(Node *r) {\n\
    \        while (r != nullptr) {\n            calc_size(r);\n            r = r->parent;\n\
    \        }\n    };\n\n    uint order_of(T x) {\n        uint index = 0;\n    \
    \    Node *w = root;\n\n        while (w != nullptr) {\n            bool c1 =\
    \ cmp(w->dat, x);\n            bool c2 = cmp(x, w->dat);\n\n            if (c1)\
    \ {\n                index += size(w->left) + 1;\n                w = w->right;\n\
    \            }\n            else if (c2) {\n                w = w->left;\n   \
    \         }\n            else {\n                index += size(w->left);\n   \
    \             return index;\n            }\n        }\n\n        return -1;\n\
    \    };\n    T find_Kth_element(uint k) {\n        Node *w = root;\n        uint\
    \ index = size(w->left);\n\n        assert(k < size(root));\n\n        while (w\
    \ != nullptr && index != k) {\n            if (index > k) {\n                w\
    \ = w->left;\n                index -= size(w->right) + 1;\n            }\n  \
    \          else if (index < k) {\n                w = w->right;\n            \
    \    index += size(w->left) + 1;\n            }\n        }\n\n        return w->dat;\n\
    \    };\n    \n    // suc:true, faile:false\n    bool insert(T x) {\n        Node\
    \ *u = Traits::allocate(alc, 1);\n        Traits::construct(alc, u, x, (uint64)rnd());\n\
    \        Node *w = find_last_node(x);\n\n        if (w == nullptr) {\n       \
    \     root = u;\n            return true;\n        }\n        else if(add_child(w,\
    \ u)) {\n            upward_calc_size(u);\n            \n            babble_up(u);\n\
    \            return true;\n        }\n\n        Traits::deallocate(alc, u, 1);\n\
    \        return false;\n    };\n    bool erase(T x) {\n        Node *u = find_last_node(x);\n\
    \        Node *p = u->parent;\n\n        if (u == nullptr || cmp(u->dat, x) ||\
    \ cmp(x, u->dat)) return false;\n\n        if (size(root) == 1) {\n          \
    \  root = nullptr;\n            Traits::deallocate(alc, u, 1);\n            return\
    \ true;\n        }\n\n        trickle_down(u);\n        p = u->parent;\n     \
    \   if (p->left == u) p->left = nullptr;\n        else p->right = nullptr;\n\n\
    \        upward_calc_size(u);\n\n        Traits::deallocate(alc, u, 1);\n    \
    \    \n        return true;\n    };\n\n    Node *find_last_node(T x) {\n     \
    \   Node *w = root;\n        Node *prev = nullptr;\n\n        while (w != nullptr)\
    \ {\n            prev = w;\n            bool c1 = cmp(w->dat, x);\n          \
    \  bool c2 = cmp(x, w->dat);\n\n            if (c1) w = w->right;\n          \
    \  else if (c2) w = w->left;\n            else return w;\n        }\n        \n\
    \        return prev;\n    };\n    \n    bool add_child(Node *p, Node *u) {\n\
    \        bool c1 = cmp(p->dat, u->dat);\n        bool c2 = cmp(u->dat, p->dat);\n\
    \n        if (p == u) return false;\n        if (!c1 && !c2) return false;\n \
    \       else if (c1) p->right = u;\n        else p->left = u;\n        \n    \
    \    u->parent = p;\n        \n        calc_size(u);\n        calc_size(p);\n\
    \        \n        return true;\n    };\n\n    void babble_up(Node *u) {\n   \
    \     while (u->parent != nullptr && u->parent->p > u->p) {\n            if (u->parent->right\
    \ == u) rotate_left(u->parent);\n            else rotate_right(u->parent);\n \
    \       }\n        \n        if (u->parent == nullptr) root = u;\n    };\n   \
    \ void trickle_down(Node *u) {\n        while (u->left != nullptr || u->right\
    \ != nullptr) {\n            if (u->left == nullptr) rotate_left(u);\n       \
    \     else if (u->right == nullptr) rotate_right(u);\n            else if (u->left->p\
    \ < u->right->p) rotate_right(u);\n            else rotate_left(u);\n        }\n\
    \    };\n    \n    void rotate_left(Node *u) {\n        Node *w = u->right;\n\
    \        w->parent = u->parent;\n        u->parent = w;\n        \n        u->right\
    \ = w->left;\n        if (u->right != nullptr) u->right->parent = u;\n       \
    \ \n        w->left = u;\n        \n        if (w->parent != nullptr) {\n    \
    \        if (w->parent->left == u) w->parent->left = w;\n            else w->parent->right\
    \ = w;\n        }\n        else {\n            root = w;\n        }\n\n      \
    \  calc_size(u);\n        calc_size(w);\n    };\n    void rotate_right(Node *u)\
    \ {\n        Node *w = u->left;\n        w->parent = u->parent;\n        u->parent\
    \ = w;\n\n        u->left = w->right;\n        if (u->left != nullptr) u->left->parent\
    \ = u;\n        \n        w->right = u;\n\n        if (w->parent != nullptr) {\n\
    \            if (w->parent->left == u) w->parent->left = w;\n            else\
    \ w->parent->right = w;\n        }\n        else {\n            root = w;\n  \
    \      }\n\n        calc_size(u);\n        calc_size(w);\n    };\n\n#ifndef NODEBUG\n\
    \    void dump(void) {\n        cout << \"Treap state.\" << endl;\n        cout\
    \ << \"size: \" << size(root) << endl;\n\n        dump(root, 0);\n    };\n   \
    \ void dump(Node *u, int h) {\n        if (u == nullptr) return;\n\n        dump(u->right,\
    \ h + 1);\n\n        for (int i = 0; i < 4 * h; i++) putchar(' ');\n        cout\
    \ << u->dat.idx << ',' << u->dat.point << endl;\n\n        dump(u->left, h + 1);\n\
    \    };\n#else\n    void dump(void) {};\n    void dump(Node *u, int h) {};\n#endif\n\
    };\n//===\n\nint pck2016_pre09() {\n    \n    struct Team {\n        ll idx, point;\n\
    \n        Team(ll idx, ll point): idx(idx), point(point) {}\n\n        bool operator\
    \ < (const Team &r)const {\n            if (this->point > r.point) {\n       \
    \         return true;\n            }\n            else if (this->point == r.point)\
    \ {\n                if (this->idx < r.idx) {\n                    return true;\n\
    \                }\n                else {\n                    return false;\n\
    \                }\n            }\n            else {\n                return\
    \ false;\n            }\n        }\n    };\n\n    ll n, c;\n    static ll p[100005];\n\
    \    ll com, t, m;\n    Treap<Team> st;\n\n    cin >> n >> c;\n\n    for (int\
    \ i = 1; i <= n; i++) {\n        //st.dump();\n        st.insert(Team(i, 0));\n\
    \    }\n\n    //st.dump();\n\n    while(c--) {\n        cin >> com;\n\n      \
    \  if (com == 0) {\n            cin >> t >> m;\n            Team d = Team(t, p[t]);\n\
    \            st.erase(d);\n\n            p[t] += m;\n            d.point += m;\n\
    \            st.insert(d);\n        }\n        else if (com == 1) {\n        \
    \    cin >> m;\n            Team d = st.find_Kth_element(m - 1);\n           \
    \ cout << d.idx << ' ' << d.point << endl;\n        }\n\n        //st.dump();\n\
    \    }\n    \n    return 0;\n}\n\nint ARC033C() {\n    Treap<int> st;\n    int\
    \ q;\n    int t, x;\n\n    cin >> q;\n\n    while (q--) {\n        cin >> t >>\
    \ x;\n\n        if (t == 1) {\n            st.insert(x);\n        }\n        else\
    \ if (t == 2) {\n            cout << st.find_Kth_element(x - 1) << endl;\n   \
    \         st.erase(st.find_Kth_element(x - 1));\n        }\n    }\n\n    return\
    \ 0;\n}\n\nint main() {\n    return ARC033C();\n    //return pck2016_pre09();\n\
    }\n\n"
  code: "#ifndef TREAP_SET\n#define TREAP_SET\n\n#include <iostream>\n#include <cstdint>\n\
    #include <random>\n#include <functional>\n#include <cassert>\n#include <memory>\n\
    using namespace std;\nusing ll = long long;\n\n//===\ntemplate <class T, class\
    \ Compare = less<T>,\n          template<class> class Alloc = allocator>\nstruct\
    \ Treap {\n    using uint = uint_fast32_t;\n    using uint64 = uint_fast64_t;\n\
    \    \n    struct Node {\n        T dat;\n        uint64 p;\n\n        uint sz\
    \ = 1;\n        Node *parent;\n        Node *left;\n        Node *right;\n\n \
    \       Node(T dat, uint64 p):\n            dat(dat), p(p), parent(nullptr), left(nullptr),\
    \ right(nullptr) {}\n    };\n    \n    Node *root;\n    const Compare cmp;\n \
    \   mt19937 rnd;\n    \n    Alloc<Node> alc;\n    using Traits = allocator_traits<Alloc<Node>\
    \ >;\n    \n    Treap(const Compare &cmp = Compare()):\n        root(nullptr),\
    \ cmp(cmp), rnd(mt19937(random_device()())) {};\n    \n    void clear(Node *u)\
    \ {\n        if (u == nullptr) return;\n        clear(u->left);\n        clear(u->right);\n\
    \        Traits::deallocate(alc, u, 1);\n    };\n    ~Treap() {\n        clear(root);\n\
    \    };\n    \n    bool has_element(T x) {\n        Node *w = root;\n\n      \
    \  while (w != nullptr) {\n            bool c1 = cmp(w->dat, x);\n           \
    \ bool c2 = cmp(x, w->dat);\n            \n            if (c1) w = w->right;\n\
    \            else if (c2) w = w->left;\n            else return true;\n      \
    \  }\n        return false;\n    };\n    \n    uint size(Node *r) {\n        return\
    \ r == nullptr ? 0 : r->sz;\n    };\n    uint size() {\n        return size(root);\n\
    \    };\n    uint calc_size(Node *r) {\n        r->sz = size(r->left) + size(r->right)\
    \ + 1;\n        return r->sz;\n    };\n    void upward_calc_size(Node *r) {\n\
    \        while (r != nullptr) {\n            calc_size(r);\n            r = r->parent;\n\
    \        }\n    };\n\n    uint order_of(T x) {\n        uint index = 0;\n    \
    \    Node *w = root;\n\n        while (w != nullptr) {\n            bool c1 =\
    \ cmp(w->dat, x);\n            bool c2 = cmp(x, w->dat);\n\n            if (c1)\
    \ {\n                index += size(w->left) + 1;\n                w = w->right;\n\
    \            }\n            else if (c2) {\n                w = w->left;\n   \
    \         }\n            else {\n                index += size(w->left);\n   \
    \             return index;\n            }\n        }\n\n        return -1;\n\
    \    };\n    T find_Kth_element(uint k) {\n        Node *w = root;\n        uint\
    \ index = size(w->left);\n\n        assert(k < size(root));\n\n        while (w\
    \ != nullptr && index != k) {\n            if (index > k) {\n                w\
    \ = w->left;\n                index -= size(w->right) + 1;\n            }\n  \
    \          else if (index < k) {\n                w = w->right;\n            \
    \    index += size(w->left) + 1;\n            }\n        }\n\n        return w->dat;\n\
    \    };\n    \n    // suc:true, faile:false\n    bool insert(T x) {\n        Node\
    \ *u = Traits::allocate(alc, 1);\n        Traits::construct(alc, u, x, (uint64)rnd());\n\
    \        Node *w = find_last_node(x);\n\n        if (w == nullptr) {\n       \
    \     root = u;\n            return true;\n        }\n        else if(add_child(w,\
    \ u)) {\n            upward_calc_size(u);\n            \n            babble_up(u);\n\
    \            return true;\n        }\n\n        Traits::deallocate(alc, u, 1);\n\
    \        return false;\n    };\n    bool erase(T x) {\n        Node *u = find_last_node(x);\n\
    \        Node *p = u->parent;\n\n        if (u == nullptr || cmp(u->dat, x) ||\
    \ cmp(x, u->dat)) return false;\n\n        if (size(root) == 1) {\n          \
    \  root = nullptr;\n            Traits::deallocate(alc, u, 1);\n            return\
    \ true;\n        }\n\n        trickle_down(u);\n        p = u->parent;\n     \
    \   if (p->left == u) p->left = nullptr;\n        else p->right = nullptr;\n\n\
    \        upward_calc_size(u);\n\n        Traits::deallocate(alc, u, 1);\n    \
    \    \n        return true;\n    };\n\n    Node *find_last_node(T x) {\n     \
    \   Node *w = root;\n        Node *prev = nullptr;\n\n        while (w != nullptr)\
    \ {\n            prev = w;\n            bool c1 = cmp(w->dat, x);\n          \
    \  bool c2 = cmp(x, w->dat);\n\n            if (c1) w = w->right;\n          \
    \  else if (c2) w = w->left;\n            else return w;\n        }\n        \n\
    \        return prev;\n    };\n    \n    bool add_child(Node *p, Node *u) {\n\
    \        bool c1 = cmp(p->dat, u->dat);\n        bool c2 = cmp(u->dat, p->dat);\n\
    \n        if (p == u) return false;\n        if (!c1 && !c2) return false;\n \
    \       else if (c1) p->right = u;\n        else p->left = u;\n        \n    \
    \    u->parent = p;\n        \n        calc_size(u);\n        calc_size(p);\n\
    \        \n        return true;\n    };\n\n    void babble_up(Node *u) {\n   \
    \     while (u->parent != nullptr && u->parent->p > u->p) {\n            if (u->parent->right\
    \ == u) rotate_left(u->parent);\n            else rotate_right(u->parent);\n \
    \       }\n        \n        if (u->parent == nullptr) root = u;\n    };\n   \
    \ void trickle_down(Node *u) {\n        while (u->left != nullptr || u->right\
    \ != nullptr) {\n            if (u->left == nullptr) rotate_left(u);\n       \
    \     else if (u->right == nullptr) rotate_right(u);\n            else if (u->left->p\
    \ < u->right->p) rotate_right(u);\n            else rotate_left(u);\n        }\n\
    \    };\n    \n    void rotate_left(Node *u) {\n        Node *w = u->right;\n\
    \        w->parent = u->parent;\n        u->parent = w;\n        \n        u->right\
    \ = w->left;\n        if (u->right != nullptr) u->right->parent = u;\n       \
    \ \n        w->left = u;\n        \n        if (w->parent != nullptr) {\n    \
    \        if (w->parent->left == u) w->parent->left = w;\n            else w->parent->right\
    \ = w;\n        }\n        else {\n            root = w;\n        }\n\n      \
    \  calc_size(u);\n        calc_size(w);\n    };\n    void rotate_right(Node *u)\
    \ {\n        Node *w = u->left;\n        w->parent = u->parent;\n        u->parent\
    \ = w;\n\n        u->left = w->right;\n        if (u->left != nullptr) u->left->parent\
    \ = u;\n        \n        w->right = u;\n\n        if (w->parent != nullptr) {\n\
    \            if (w->parent->left == u) w->parent->left = w;\n            else\
    \ w->parent->right = w;\n        }\n        else {\n            root = w;\n  \
    \      }\n\n        calc_size(u);\n        calc_size(w);\n    };\n\n#ifndef NODEBUG\n\
    \    void dump(void) {\n        cout << \"Treap state.\" << endl;\n        cout\
    \ << \"size: \" << size(root) << endl;\n\n        dump(root, 0);\n    };\n   \
    \ void dump(Node *u, int h) {\n        if (u == nullptr) return;\n\n        dump(u->right,\
    \ h + 1);\n\n        for (int i = 0; i < 4 * h; i++) putchar(' ');\n        cout\
    \ << u->dat.idx << ',' << u->dat.point << endl;\n\n        dump(u->left, h + 1);\n\
    \    };\n#else\n    void dump(void) {};\n    void dump(Node *u, int h) {};\n#endif\n\
    };\n//===\n\nint pck2016_pre09() {\n    \n    struct Team {\n        ll idx, point;\n\
    \n        Team(ll idx, ll point): idx(idx), point(point) {}\n\n        bool operator\
    \ < (const Team &r)const {\n            if (this->point > r.point) {\n       \
    \         return true;\n            }\n            else if (this->point == r.point)\
    \ {\n                if (this->idx < r.idx) {\n                    return true;\n\
    \                }\n                else {\n                    return false;\n\
    \                }\n            }\n            else {\n                return\
    \ false;\n            }\n        }\n    };\n\n    ll n, c;\n    static ll p[100005];\n\
    \    ll com, t, m;\n    Treap<Team> st;\n\n    cin >> n >> c;\n\n    for (int\
    \ i = 1; i <= n; i++) {\n        //st.dump();\n        st.insert(Team(i, 0));\n\
    \    }\n\n    //st.dump();\n\n    while(c--) {\n        cin >> com;\n\n      \
    \  if (com == 0) {\n            cin >> t >> m;\n            Team d = Team(t, p[t]);\n\
    \            st.erase(d);\n\n            p[t] += m;\n            d.point += m;\n\
    \            st.insert(d);\n        }\n        else if (com == 1) {\n        \
    \    cin >> m;\n            Team d = st.find_Kth_element(m - 1);\n           \
    \ cout << d.idx << ' ' << d.point << endl;\n        }\n\n        //st.dump();\n\
    \    }\n    \n    return 0;\n}\n\nint ARC033C() {\n    Treap<int> st;\n    int\
    \ q;\n    int t, x;\n\n    cin >> q;\n\n    while (q--) {\n        cin >> t >>\
    \ x;\n\n        if (t == 1) {\n            st.insert(x);\n        }\n        else\
    \ if (t == 2) {\n            cout << st.find_Kth_element(x - 1) << endl;\n   \
    \         st.erase(st.find_Kth_element(x - 1));\n        }\n    }\n\n    return\
    \ 0;\n}\n\nint main() {\n    return ARC033C();\n    //return pck2016_pre09();\n\
    }\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: bbst/set/insert_erase_treap.cpp
  requiredBy: []
  timestamp: '2020-06-11 01:24:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bbst/set/insert_erase_treap.cpp
layout: document
redirect_from:
- /library/bbst/set/insert_erase_treap.cpp
- /library/bbst/set/insert_erase_treap.cpp.html
title: bbst/set/insert_erase_treap.cpp
---

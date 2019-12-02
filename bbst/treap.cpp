#include <iostream>
#include <cstdint>
#include <random>
#include <functional>
#include <cassert>
#include <memory>
using namespace std;
using ll = long long;

//===
template <class T, class Compare = less<T>,
          template<class> class Alloc = allocator>
struct Treap {
    using uint = uint_fast32_t;
    using uint64 = uint_fast64_t;
    
    struct Node {
        T dat;
        uint64 p;

        uint sz = 1;
        Node *parent;
        Node *left;
        Node *right;

        Node(T dat, uint64 p):
            dat(dat), p(p), parent(nullptr), left(nullptr), right(nullptr) {}
    };
    
    Node *root;
    const Compare cmp;
    mt19937 rnd;
    
    Alloc<Node> alc;
    using Traits = allocator_traits<Alloc<Node> >;
    
    Treap(const Compare &cmp = Compare()):
        root(nullptr), cmp(cmp), rnd(mt19937(random_device()())) {};
    
    void clear(Node *u) {
        if (u == nullptr) return;
        clear(u->left);
        clear(u->right);
        Traits::deallocate(alc, u, 1);
    };
    ~Treap() {
        clear(root);
    };
    
    bool has_element(T x) {
        Node *w = root;

        while (w != nullptr) {
            bool c1 = cmp(w->dat, x);
            bool c2 = cmp(x, w->dat);
            
            if (c1) w = w->right;
            else if (c2) w = w->left;
            else return true;
        }
        return false;
    };
    
    uint size(Node *r) {
        return r == nullptr ? 0 : r->sz;
    };
    uint size() {
        return size(root);
    };
    uint calc_size(Node *r) {
        r->sz = size(r->left) + size(r->right) + 1;
        return r->sz;
    };
    void upward_calc_size(Node *r) {
        while (r != nullptr) {
            calc_size(r);
            r = r->parent;
        }
    };

    uint order_of(T x) {
        uint index = 0;
        Node *w = root;

        while (w != nullptr) {
            bool c1 = cmp(w->dat, x);
            bool c2 = cmp(x, w->dat);

            if (c1) {
                index += size(w->left) + 1;
                w = w->right;
            }
            else if (c2) {
                w = w->left;
            }
            else {
                index += size(w->left);
                return index;
            }
        }

        return -1;
    };
    T find_Kth_element(uint k) {
        Node *w = root;
        uint index = size(w->left);

        assert(k < size(root));

        while (w != nullptr && index != k) {
            if (index > k) {
                w = w->left;
                index -= size(w->right) + 1;
            }
            else if (index < k) {
                w = w->right;
                index += size(w->left) + 1;
            }
        }

        return w->dat;
    };
    
    // suc:true, faile:false
    bool insert(T x) {
        Node *u = Traits::allocate(alc, 1);
        Traits::construct(alc, u, x, (uint64)rnd());
        Node *w = find_last_node(x);

        if (w == nullptr) {
            root = u;
            return true;
        }
        else if(add_child(w, u)) {
            upward_calc_size(u);
            
            babble_up(u);
            return true;
        }

        Traits::deallocate(alc, u, 1);
        return false;
    };
    bool erase(T x) {
        Node *u = find_last_node(x);
        Node *p = u->parent;

        if (u == nullptr || cmp(u->dat, x) || cmp(x, u->dat)) return false;

        if (size(root) == 1) {
            root = nullptr;
            Traits::deallocate(alc, u, 1);
            return true;
        }

        trickle_down(u);
        p = u->parent;
        if (p->left == u) p->left = nullptr;
        else p->right = nullptr;

        upward_calc_size(u);

        Traits::deallocate(alc, u, 1);
        
        return true;
    };

    Node *find_last_node(T x) {
        Node *w = root;
        Node *prev = nullptr;

        while (w != nullptr) {
            prev = w;
            bool c1 = cmp(w->dat, x);
            bool c2 = cmp(x, w->dat);

            if (c1) w = w->right;
            else if (c2) w = w->left;
            else return w;
        }
        
        return prev;
    };
    
    bool add_child(Node *p, Node *u) {
        bool c1 = cmp(p->dat, u->dat);
        bool c2 = cmp(u->dat, p->dat);

        if (p == u) return false;
        if (!c1 && !c2) return false;
        else if (c1) p->right = u;
        else p->left = u;
        
        u->parent = p;
        
        calc_size(u);
        calc_size(p);
        
        return true;
    };

    void babble_up(Node *u) {
        while (u->parent != nullptr && u->parent->p > u->p) {
            if (u->parent->right == u) rotate_left(u->parent);
            else rotate_right(u->parent);
        }
        
        if (u->parent == nullptr) root = u;
    };
    void trickle_down(Node *u) {
        while (u->left != nullptr || u->right != nullptr) {
            if (u->left == nullptr) rotate_left(u);
            else if (u->right == nullptr) rotate_right(u);
            else if (u->left->p < u->right->p) rotate_right(u);
            else rotate_left(u);
        }
    };
    
    void rotate_left(Node *u) {
        Node *w = u->right;
        w->parent = u->parent;
        u->parent = w;
        
        u->right = w->left;
        if (u->right != nullptr) u->right->parent = u;
        
        w->left = u;
        
        if (w->parent != nullptr) {
            if (w->parent->left == u) w->parent->left = w;
            else w->parent->right = w;
        }
        else {
            root = w;
        }

        calc_size(u);
        calc_size(w);
    };
    void rotate_right(Node *u) {
        Node *w = u->left;
        w->parent = u->parent;
        u->parent = w;

        u->left = w->right;
        if (u->left != nullptr) u->left->parent = u;
        
        w->right = u;

        if (w->parent != nullptr) {
            if (w->parent->left == u) w->parent->left = w;
            else w->parent->right = w;
        }
        else {
            root = w;
        }

        calc_size(u);
        calc_size(w);
    };

#ifndef NODEBUG
    void dump(void) {
        cout << "Treap state." << endl;
        cout << "size: " << size(root) << endl;

        dump(root, 0);
    };
    void dump(Node *u, int h) {
        if (u == nullptr) return;

        dump(u->right, h + 1);

        for (int i = 0; i < 4 * h; i++) putchar(' ');
        cout << u->dat.idx << ',' << u->dat.point << endl;

        dump(u->left, h + 1);
    };
#else
    void dump(void) {};
    void dump(Node *u, int h) {};
#endif
};
//===

int pck2016_pre09() {
    
    struct Team {
        ll idx, point;

        Team(ll idx, ll point): idx(idx), point(point) {}

        bool operator < (const Team &r)const {
            if (this->point > r.point) {
                return true;
            }
            else if (this->point == r.point) {
                if (this->idx < r.idx) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    };

    ll n, c;
    static ll p[100005];
    ll com, t, m;
    Treap<Team> st;

    cin >> n >> c;

    for (int i = 1; i <= n; i++) {
        //st.dump();
        st.insert(Team(i, 0));
    }

    //st.dump();

    while(c--) {
        cin >> com;

        if (com == 0) {
            cin >> t >> m;
            Team d = Team(t, p[t]);
            st.erase(d);

            p[t] += m;
            d.point += m;
            st.insert(d);
        }
        else if (com == 1) {
            cin >> m;
            Team d = st.find_Kth_element(m - 1);
            cout << d.idx << ' ' << d.point << endl;
        }

        //st.dump();
    }
    
    return 0;
}

int ARC033C() {
    Treap<int> st;
    int q;
    int t, x;

    cin >> q;

    while (q--) {
        cin >> t >> x;

        if (t == 1) {
            st.insert(x);
        }
        else if (t == 2) {
            cout << st.find_Kth_element(x - 1) << endl;
            st.erase(st.find_Kth_element(x - 1));
        }
    }

    return 0;
}

int main() {
    return ARC033C();
    //return pck2016_pre09();
}

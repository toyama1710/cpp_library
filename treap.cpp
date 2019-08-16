#include <iostream>
#include <cstdint>
#include <random>
#include <functional>
using namespace std;

//===
// 2019/08/16 Todo:insert(), erase() and so on
// 2019/08/17 Todo:operators, lower_bound(), upper_bound(), Kth_element()
template <typename T, typename Compare = less<T>>
struct Treap {
    using uint = uint_fast32_t;
    
    struct Node {
        T dat;
        uint p;

        Node &parent;
        Node &l, &r;

        Node(T dat, uint p, Node &l = nullptr, Node &r = nullptr, Node &parent = nullptr):
            dat(dat), p(p), parent(parent), l(l), r(r) {}
    };

    Compare cmp;
    mt19937 rnd;

    Node &root = nullptr;

    Treap(Compare &cmp = Compare()):cmp(cmp) {
        random_device rd();
        rnd = mt19937(rd());
    }
};
//===

int main() {

    return 0;
}

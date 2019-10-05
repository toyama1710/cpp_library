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
using namespace std;
template<class T, class Compare = less<T> >
using MaxHeap = priority_queue<T, vector<T>, Compare>;
template<class T, class Compare = greater<T> >
using MinHeap = priority_queue<T, vector<T>, Compare>;
using llong = long long;

//===
template<typename T, typename Compare = less<T> >
struct AVLTree {
    enum direction {L = 1, R = 0};
    direction inv_dir(direction d) {return 1 - d;};
    
    struct Node {
        T data;
        int height;
        Node *ch[2]; //0:left, 1:right

        Node(T data):data(data), height(0), ch{nullptr, nullptr} {};
    };

    Node *root;
    Compare cmp;

    AVLTree(Compare cmp = Compare()):root(nullptr), cmp(cmp) {}
        
    int height() { return height(root); };
    int height(Node *p) {
        return p == nullptr ? -1 : p->height;
    };

    // d=L:left-rotate; u move to left
    // d=R:right-rotate;
    template<int d>
    Node *rotate(Node *u) {
        Node w = u->ch[d];
        u->ch[d] = w->ch[inv_dir(d)];
        w->ch[inv_dir(d)] = u;
        // update(u); update(w);
        return w;
    };

    void insert(T data) { insert(root, new Node(data)); };
    Node *insert(Node *r, Node *p, T data) {
    };
};
//===

int main() {
    return 0;
}

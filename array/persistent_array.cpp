#include <iostream>
#include <functional>
#include <vector>
#include <memory>
#include <cstring>
using namespace std;
using llong = long long;

//===
// K-ary tree
template<class T, int K = 2, template<class> class Alloc = allocator>
struct PersistentArray {
    struct Node;
    using Leaf = T;
    struct Node {
        T dat;
        Node* ch[K] = {};

        Node() = default;
        Node(Node *np) {
            dat = np->dat;
            memcpy(ch, np->ch, sizeof(Node *) * K);
        };
    };

    Node *root;
    int arr_size;

    PersistentArray (Node *root, int arr_size):root(root), arr_size(arr_size) {};
    PersistentArray(int size, const T &d = T()):arr_size(size) {
        root = new Node();
        init(root, size, d);
    };
    Node *init(Node *np, int size, T d) {
        np->dat = d;
                             
        if (size == 1) return np;
        for (int i = 0; i < min(K, size); i++) {
            np->ch[i] = init(new Node(), (size + K - 1) / K, d);
        }
        return np;
    };

    T get(int idx) {
        return get(idx, root);
    };
    T get(int idx, Node *np) {
        if (idx == 0) return np->dat;
        return get((idx - 1) / K, np->ch[idx % K]);
    };
    
    PersistentArray set(int idx, const T &val) {
        return {set(idx, val, root), arr_size};
    };
    Node *set(int idx, const T &val, Node *np) {
        if (idx == 0) {
            Node *node = new Node(np);
            node->dat = val;
            return node;
        }
        else {
            Node *node = new Node(np);
            node->ch[idx % K] = set((idx - 1) / K, val, np->ch[idx % K]);
            return node;
        }
    };

    void destructive_set(int idx, const T &val) {
        destructive_set(idx, val, root);
    };
    void destructive_set(int idx, const T &val, Node *np) {
        if (idx == 0) np->dat = val;
        else destructive_set((idx - 1) / K, val, np->ch[idx % K]);
    };

    int size() {
        return arr_size;
    };
    PersistentArray get_array() {
        return *this;
    };
};
//===


llong n, q;
vector<llong> v;

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        llong a;
        cin >> a;
        v.push_back(a);
    }

    vector<PersistentArray<llong>> r;
    PersistentArray<llong> arr(v.size());
    for (int i = 0; i < arr.size(); i++) {
        arr.destructive_set(i, v[i]);
    }
    r.push_back(arr);

    for (int i = 0; i < q; i++) {
        llong com;
        llong idx, dat;

        cin >> com;
        if (com == 0) {
            cin >> idx >> dat;
            r.push_back(r.back().set(idx, dat));
        }
        else {
            cout << "=====" << endl;
            for (int i = 0; i < r.size(); i++) {
                for (int j = 0; j < r[i].size(); j++) {
                    cout << r[i].get(j) << ' ';
                }
                cout << endl;
            }
            cout << "=====" << endl;
        }
    }

    return 0;
}

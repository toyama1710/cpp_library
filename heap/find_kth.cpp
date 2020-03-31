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

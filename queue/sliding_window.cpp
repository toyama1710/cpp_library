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
    using Stack = stack<SemiGroup>;
    const OP merge;
    Stack front_st, back_st;
    Stack front_sum, back_sum;
    size_t sz;

    SlidingWindow(const OP &f):merge(f) {
        sz = 0;
    };

    SemiGroup fold() {
        assert(sz > 0);
        
        if (front_sum.empty()) return back_sum.top();
        else if (back_sum.empty()) return front_sum.top();
        else return merge(front_sum.top(), back_sum.top());
    };

    void push(SemiGroup d) {
        sz++;
        back_st.push(d);
        if (back_sum.empty()) back_sum.push(d);
        else back_sum.push(merge(back_sum.top(), d));
    };

    void pop() {
        assert(sz > 0);

        sz--;
        if (front_st.empty()) {
            front_st.push(back_st.top());
            front_sum.push(back_st.top());
            back_st.pop();
            back_sum.pop();
            
            while (!back_st.empty()) {
                front_st.push(back_st.top());
                front_sum.push(merge(front_sum.top(), back_st.top()));
                back_st.pop();
                back_sum.pop();
            }
        }
        
        front_st.pop();
        front_sum.pop();
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
        smin.push(arr[i]);
    }

    cout << smin.fold();
    for (int i = l; i < n; i++) {
        smin.pop();
        smin.push(arr[i]);

        cout << ' ' << smin.fold();
    }
    cout << endl;

    return 0;
}

int main() {
    return AOJ_DSL3D();
}

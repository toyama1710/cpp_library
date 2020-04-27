#include <iostream>
#include <cstdio>
#include <cassert>
#include <functional>
#include <stack>

//===
// LIBRARY SECTION

// #include <stack>
// #include <cassert>
template<class SemiGroup, class OP = std::function<SemiGroup(SemiGroup, SemiGroup)> >
struct QueueAggregation {
    using Stack = std::stack<std::pair<SemiGroup, SemiGroup>>;
    const OP merge;
    Stack front_st, back_st;

    QueueAggregation(const OP &f):merge(f) {};

    SemiGroup fold() {
        assert(!empty());
        
        if (front_st.empty()) return back_st.top().second;
        else if (back_st.empty()) return front_st.top().second;
        else return merge(front_st.top().second, back_st.top().second);
    };

    void push(SemiGroup d) {
        if (back_st.empty()) back_st.emplace(d, d);
        else back_st.emplace(d, merge(back_st.top().second, d));
    };

    void pop() {
        assert(!empty());

        if (front_st.empty()) {
            front_st.emplace(back_st.top().first, back_st.top().first);
            back_st.pop();
            
            while (!back_st.empty()) {
                front_st.emplace(back_st.top().first, merge(back_st.top().first, front_st.top().second));
                back_st.pop();
            }
        }
        
        front_st.pop();
    };

    bool empty() {
        return size() == 0;
    };

    size_t size() {
        return front_st.size() + back_st.size();
    };
};
//===

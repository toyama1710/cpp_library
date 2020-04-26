#include <iostream>
#include <cstdio>
#include <cassert>
#include <functional>
#include <stack>

//===
// #include <stack>
// #include <cassert>
template<class SemiGroup, class OP = std::function<SemiGroup(SemiGroup, SemiGroup)> >
struct SlidingWindow {
    using Stack = std::stack<std::pair<SemiGroup, SemiGroup> >;
    const OP merge;

    Stack front_st, back_st;
    size_t sz;

    SlidingWindow(const OP &f):merge(f) {
        sz = 0;
    };

    SemiGroup fold() {
        assert(sz > 0);
        
        if (front_st.empty()) return back_st.top().second;
        else if (back_st.empty()) return front_st.top().second;
        else return merge(front_st.top().second, back_st.top().second);
    };

    void push(SemiGroup d, Stack &front_stack, Stack &back_stack) {
        sz++;
        if (back_stack.empty()) back_stack.push({d, d});
        else back_stack.push({d, merge(back_stack.top().second, d)});
    };

    void pop(Stack &front_stack, Stack &back_stack) {
        assert(!empty());
        sz--;
        
        if (front_stack.empty()) {
            Stack buff;

            while (buff.size() + 1 < back_stack.size()) {
                buff.push(back_stack.top());
                back_stack.pop();
            }

            while (!back_stack.empty()) {
                if (front_stack.empty()) front_stack.push({back_stack.top().first,
                                                           back_stack.top().first});
                else front_stack.push({back_stack.top().first,
                                       merge(back_stack.top().first, front_stack.top().second)});
                back_stack.pop();
            }
            
            while (!buff.empty()) {
                if (back_stack.empty()) back_stack.push({buff.top().first,
                                                         buff.top().first});
                else back_stack.push({buff.top().first,
                                      merge(back_stack.top().second, buff.top().first)});
                buff.pop();
            }
        }
        front_stack.pop();
    };

    void push_front(SemiGroup d) {
        push(d, back_st, front_st);
    };
    void push_back(SemiGroup d) {
        push(d, front_st, back_st);
    };

    void pop_front() {
        pop(front_st, back_st);
    };
    void pop_back() {
        pop(back_st, front_st);
    };
    
    bool empty() {
        return sz == 0;
    };

    size_t size() {
        return sz;
    };
};
//===

#include <cassert>
#include <cstdio>
#include <functional>
#include <iostream>
#include <stack>

//===
// LIBRARY SECTION

// #include <stack>
// #include <cassert>
template <class SemiGroup,
          class OP = std::function<SemiGroup(SemiGroup, SemiGroup)> >
struct SlidingWindow {
    // first:original data, second:sum
    using Stack = std::stack<std::pair<SemiGroup, SemiGroup> >;
    const OP merge;

    Stack front_st, back_st;

    SlidingWindow(const OP &f) : merge(f){};

    inline SemiGroup fold() {
        assert(!empty());

        if (front_st.empty())
            return back_st.top().second;
        else if (back_st.empty())
            return front_st.top().second;
        else
            return merge(front_st.top().second, back_st.top().second);
    };

    inline void push_front(SemiGroup d) {
        if (front_st.empty())
            front_st.emplace(d, d);
        else
            front_st.emplace(d, merge(d, front_st.top().second));
    };
    inline void push_back(SemiGroup d) {
        if (back_st.empty())
            back_st.emplace(d, d);
        else
            back_st.emplace(d, merge(back_st.top().second, d));
    };

    void pop_front() {
        assert(!empty());

        if (front_st.empty()) {
            Stack buff;
            while (buff.size() + 1 < back_st.size()) {
                buff.push(back_st.top());
                back_st.pop();
            }
            while (!back_st.empty()) {
                push_front(back_st.top().first);
                back_st.pop();
            }
            while (!buff.empty()) {
                push_back(buff.top().first);
                buff.pop();
            }
        }
        front_st.pop();
    };
    void pop_back() {
        assert(!empty());

        if (back_st.empty()) {
            Stack buff;
            while (buff.size() + 1 < front_st.size()) {
                buff.push(front_st.top());
                front_st.pop();
            }
            while (!front_st.empty()) {
                push_back(front_st.top().first);
                front_st.pop();
            }
            while (!buff.empty()) {
                push_front(buff.top().first);
                buff.pop();
            }
        }
        back_st.pop();
    };

    inline bool empty() {
        return size() == 0;
    };

    inline size_t size() {
        return front_st.size() + back_st.size();
    };
};
//===

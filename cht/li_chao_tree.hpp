#ifndef LI_CHAO_TREE_HPP
#define LI_CHAO_TREE_HPP

#include <vector>
#include <algorithm>
#include <limits>
#include <numeric>
#include <iterator>

template <class T = long long>
struct LiChaoTree {
    struct Line {
        T a, b;
        Line (T a, T b):
            a(a), b(b) {};
        T get(T x) {
            return a * x + b;
        };
        inline static Line identity() {
            return Line(0, std::numeric_limits<T>::max());
        };
    };

    std::vector<Line> seg;
    std::vector<T> pos;

    LiChaoTree() = default;
    explicit LiChaoTree(int n):seg(n << 1, Line::identity()), pos(n) {
        std::iota(pos.begin(), pos.end(), 0);
    };
    template<class InputItr>
    LiChaoTree(InputItr first, InputItr last):
        seg(std::distance(first, last) << 1, Line::identity()), pos(first, last)
    {};

    int size() {
        return  seg.size() >> 1;
    };

    void add_line(T a, T b) {
        add_segment(a, b, pos[0], pos.back());
    };
    void add_segment(T a, T b, T s, T t) {
        Line x(a, b);
        int l = std::lower_bound(pos.begin(), pos.end(), l) - pos.begin() + size();
        int r = std::lower_bound(pos.begin(), pos.end(), r) - pos.begin() + size();
        int ll = l, lr = l + 1;
        int rl = r - 1, rr = r;
        while (l < r) {
            if (l & 1) {
                update(x, l, ll, lr);
                l++;
                int range = lr - ll;
                ll += range;
                lr += range;
            }
            if (r & 1) {
                r--;
                update(x, r, rl, rr);
                int range = rr - rl;
                rl -= range;
                rr -= range;
            }
            l >>= 1;
            lr += lr - ll;
            r >>= 1;
            rl -= rr - rl;
        }
    };

    void update(Line &x, int k, int l, int r) {
        T pl = pos[l];
        T pr = pos[r - 1];
        if (x.get(pl) <= seg[k].get(pl) && x.get(pr) <= seg[k].get(pr)) {
            seg[k] = x;
        }
        else if (x.get(pl) < seg[k].get(pl) || x.get(pr) < seg[k].get(pr)) {
            update(x, k << 1, l, (l + r) >> 1);
            update(x, (k << 1) | 1, (l + r) >> 1, r);
        }
    };

    T get(int x) {
        int k = std::lower_bound(pos.begin(), pos.end(), x) - pos.begin() + size();

        T ret = seg[k].get(x);
        while (k > 0) {
            k >>= 1;
            ret = std::min(ret, seg[k].get(x));
        }
        return ret;
    };
};

#endif

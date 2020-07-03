#ifndef LI_CHAO_TREE_HPP
#define LI_CHAO_TREE_HPP

#include <vector>
#include <algorithm>
#include <limits>

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

    LiChaoTree() = default;
    explicit LiChaoTree(int n):seg(n << 1, Line::identity()) {};

    int size() {
        return  seg.size() >> 1;
    };

    void add_segment(T a, T b, int l, int r) {
        Line x(a, b);
        int ll = l, lr = l + 1;
        int rl = r - 1, rr = r;
        l += size();
        r += size();
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
        //replace
        if (x.get(l) <= seg[k].get(l) && x.get(r - 1) <= seg[k].get(r - 1)) seg[k] = x;
        //left
        else if (x.get(l) < seg[k].get(l)) update(x, k << 1, l, (l + r) >> 1);
        //right
        else if (x.get(r - 1) < seg[k].get(r - 1)) update(x, (k << 1) | 1, (l + r) >> 1, r);
        else return;
    };

    T get(int x) {
        int k = x + size();
        T ret = seg[k].get(x);
        while (k > 0) {
            k >>= 1;
            ret = std::min(ret, seg[k].get(x));
        }
        return ret;
    };
};

#endif

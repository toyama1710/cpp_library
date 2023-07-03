#ifndef LI_CHAO_TREE_HPP
#define LI_CHAO_TREE_HPP

#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>
#include <vector>

template <class T = long long>
struct LiChaoTree {
    struct Line {
        T a, b;
        Line(T a, T b) : a(a), b(b){};
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
    explicit LiChaoTree(int n) {
        int n_ = 1;
        while (n_ < n) n_ *= 2;
        seg.resize(n_ * 2, Line::identity());
        pos.resize(n_);
        std::iota(pos.begin(), pos.end(), T(0));
    };

    template <class InputItr>
    LiChaoTree(InputItr first, InputItr last) {
        init(first, last);
    };

    LiChaoTree(std::vector<T> p) {
        std::sort(p.begin(), p.end());
        p.erase(std::unique(p.begin(), p.end()), p.end());
        init(p.begin(), p.end());
    };

    template <class InputItr>
    void init(InputItr first, InputItr last) {
        int n = std::distance(first, last);
        int n_ = 1;

        while (n_ < n) n_ *= 2;

        seg.resize(n_ * 2, Line::identity());
        pos.reserve(n_);
        for (; first != last; first++) pos.push_back(*first);
        while (pos.size() < n_) pos.push_back(pos.back() + 1);
    }

    int size() {
        return seg.size() >> 1;
    };

    void add_line(T a, T b) {
        update(Line(a, b), 1, 0, size() - 1);
    };

    // [s, t)
    void add_segment(T a, T b, T s, T t) {
        Line x(a, b);
        int sl, tl;
        int len = 1;

        sl = std::lower_bound(pos.begin(), pos.end(), s) - pos.begin();
        tl = std::lower_bound(pos.begin(), pos.end(), t) - pos.begin();

        s = std::lower_bound(pos.begin(), pos.end(), s) - pos.begin() + size();
        t = std::lower_bound(pos.begin(), pos.end(), t) - pos.begin() + size();

        while (s < t) {
            if (s & 1) {
                update(x, s, sl, sl + len - 1);
                sl += len;
                s++;
            }
            if (t & 1) {
                t--;
                tl -= len;
                update(x, t, tl, tl + len - 1);
            }
            s >>= 1;
            t >>= 1;
            len <<= 1;
        }
    };

    // [l, r]
    void update(Line x, int k, int l, int r) {
        T pl = pos[l];
        T pr = pos[r];
        T pm = pos[(l + r) / 2];

        if (x.get(pl) >= seg[k].get(pl) && x.get(pr) >= seg[k].get(pr)) return;

        if (x.get(pl) <= seg[k].get(pl) && x.get(pr) <= seg[k].get(pr)) {
            seg[k] = x;
            return;
        }

        if (x.get(pm) < seg[k].get(pm)) std::swap(x, seg[k]);
        if (x.get(pl) <= seg[k].get(pl))
            update(x, k << 1, l, (l + r) / 2);
        else
            update(x, (k << 1) | 1, (l + r) / 2 + 1, r);
    };

    T get(T x) {
        int k =
            std::lower_bound(pos.begin(), pos.end(), x) - pos.begin() + size();

        T ret = seg[k].get(x);
        while (k > 0) {
            k >>= 1;
            ret = std::min(ret, seg[k].get(x));
        }
        return ret;
    };
};

#endif

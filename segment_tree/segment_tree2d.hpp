#include <cassert>
#include <vector>

//===
// memory: O(HW)
// time: O(logH * logW)
template <class CommutativeMonoid>
struct SegmentTree2D {
    using M = CommutativeMonoid;
    using T = typename M::value_type;
    const std::size_t H, W;
    std::vector<std::vector<T>> tree;

    SegmentTree2D(size_t H, size_t W) : H(H), W(W) {
        tree.assign(H << 1, std::vector<T>(W << 1, M::identity()));
    };

    void update(int sy, int sx, T dat) {
        sy += H;
        sx += W;
        int ty, tx;
        tree[sy][sx] = dat;

        tx = sx;
        while (tx > 1) {
            tx >>= 1;
            tree[sy][tx] =
                M::operation(tree[sy][(tx << 1)], tree[sy][(tx << 1) | 1]);
        }

        ty = sy;
        while (ty > 1) {
            ty >>= 1;
            tx = sx;
            tree[ty][tx] =
                M::operation(tree[(ty << 1)][tx], tree[(ty << 1) | 1][tx]);

            while (tx > 1) {
                tx >>= 1;
                tree[ty][tx] =
                    M::operation(tree[(ty << 1)][tx], tree[(ty << 1) | 1][tx]);
            }
        }
    };

    T fold(int sy, int sx, int ty, int tx) {
        sy += H;
        ty += H;

        T ret = M::identity();
        while (sy < ty) {
            if (sy & 1) ret = M::operation(ret, fold_x(sy++, sx, tx));
            if (ty & 1) ret = M::operation(fold_x(--ty, sx, tx), ret);
            sy >>= 1;
            ty >>= 1;
        }
        return ret;
    };

    T fold_x(int y, int l, int r) {
        l += W;
        r += W;
        T ret = M::identity();

        while (l < r) {
            if (l & 1) ret = M::operation(ret, tree[y][l++]);
            if (r & 1) ret = M::operation(tree[y][--r], ret);
            l >>= 1;
            r >>= 1;
        }
        return ret;
    };

    T at(int sy, int sx) const {
        return tree[sy + H][sx + W];
    };
};
//===

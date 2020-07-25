#ifndef WAVELET_MATRIX_HPP
#define WAVELET_MATRIX_HPP

#include <vector>

// T = integer type
// LOG = bit size
// FID = FullyIndexableDictionary
template<class T, int LOG, class FID>
struct WaveletMatrix {
    int len;
    FID bits[LOG];

    WaveletMatrix() = default;
    WaveletMatrix(std::vector<T> data) {
        len = data.size();
        std::vector<T> ls(len), rs(len);
        int p = 0, q = 0;

        for (int depth = 0; depth < LOG; depth++) {
            p = q = 0;
            bits[depth] = FID(len);
            for (int i = 0; i < len; i++) {
                if ((data[i] >> (LOG - depth - 1)) & 1) {
                    bits[depth].set(i);
                    rs[q++] = data[i];
                }
                else {
                    ls[p++] = data[i];
                }
            }
            bits[depth].build();
            data.clear();
            swap(data, ls);
            for (int i = 0; i < q; i++) {
                data[i + p] = rs[i];
            }
        }
    };

    int access(int k) {
        int ret = 0;
        for (int depth = 0; depth < LOG; depth++) {
            ret <<= 1;
            ret |= bits[depth][k];
            if (bits[depth][k]) {
                k = bits[depth].rank0(len) + bits[depth].rank1(k);
            }
            else {
                k = bits[depth].rank0(k);
            }
        }
        return ret;
    };

    // count v in [0, k)
    int rank(T v, int k) {
        int l = 0;
        int r = k;
        for (int depth = 0; depth < LOG; depth++) {
            int bit = (v >> (LOG - depth - 1)) & 1;
            if (bit) {
                int b = bits[depth].rank0(len);
                l = b + bits[depth].rank1(l);
                r = b + bits[depth].rank1(r);
            }
            else {
                l = bits[depth].rank0(l);
                r = bits[depth].rank0(r);
            }
        }
        return r - l;
    };

    int less(T v, int l, int r) {
        int ret = 0;
        for (depth = 0; depth < LOG; depth++) {
            if ((v >> (LOG - depth - 1)) & 1) {
                ret += bits[depth].rank0(r) - bits[depth].rank0(l);
                int b = bits[depth].rank0(len);
                l = b + bits[depth].rank1(l);
                r = b + bits[depth].rank1(r);
            }
            else {
                l = bits[depth].rank0(l);
                r = bits[depth].rank0(r);
            }
        }
        return ret;
    };

    int range_freq(int l, int r, int lower, int upper) {
        if (lower == 0) return less(upper, l, r);
        else return less(upper, l, r) - less(lower - 1, l, r);
    };
};

#endif
#ifndef WAVELET_MATRIX_HPP
#define WAVELET_MATRIX_HPP

// T = integer type
// LOG = number of bit
// FID = FullyIndexableDictionary
template<class T, int LOG, class FID>
class WaveletMatrix {
    int len;
    FID bits[LOG];
    int zero_cnt[LOG];

    WaveletMatrix(vector<T> data) {
        len = data.size();
        std::vector<T> ls(len), rs(len);
        int p = 0, q = 0;

        for (int depth = 0; depth < LOG; depth++) {
            bits[depth] = FID(len);
            for (int i = 0; i < len; i++) {
                if ((data[i] >> (LOG - depth - 1)) & 1)) {
                    bits[depth].set(i);
                    rs[q++] = data[i];
                }
                else {
                    ls[p++] = data[i];
                }
            }
        }
        zero_cnt[depth] = p;
        bits[depth].build();
        data.clear();
        swap(data, ls);
        for (int i = 0; i < q; i++) {
            data[i + p] = rs[i];
        }
    };
};

#endif
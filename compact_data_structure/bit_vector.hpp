#ifndef BIT_VECTOR_HPP
#define BIT_VECTOR_HPP

#include <cstdint>
#include "../bit/pop_count.hpp"

struct BitVector {
    using u64 = uint64_t;
    using u32 = uint32_t;
    using u8 = uint8_t;

    vector<u32> bit;
    vector<u32> chunk;

    BitVector() = default;
    explicit BitVector(int len) : bit((len + 31) / 32, 0), chunk((len + 31) / 32, 0){};
    BitVector(vector<bool> v) : bit((v.size() + 31) / 32, 0), chunk((v.size() + 31) / 32, 0) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i]) set(i);
        }
    };
    BitVector(string s) : bit((s.size() + 31) / 32, 0), chunk((s.size() + 31) / 32, 0) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') set(i);
        }
    };

    set(int k) {
        bit[k / 32] |= 1u << (k & 31);
    };
    build() {
        for (int i = 1; i < size(); i++) {
            chunk[i] = chunk[i - 1] + popcnt32(bit[i - 1]);
        }
    };

    size() {
        return bit.size();
    };

    // count number of 1 in [0, k)
    rank1(int k) {
        return chunk[k / 32] +
        popcnt32(bit[k / 32] & (~0) >> (k & 31));
    };
    // count number of 0 in [0, k)
    rank0(int k) {
        return k - rank1(k);
    };
    select1(int k) {
        int l = 0;
        int r = size();
        int m;
        while (r - l > 1) {
            m = (l + r) >> 1;
            if (rank1(m) >= k) r = m;
            else l = m;
        }
        return r - 1;
    };
    select0(int k) {
        int l = 0;
        int r = size();
        int m;
        while (r - l > 1) {
            m = (l + r) >> 1;
            if (rank0(m) >= k) r = m;
            else l = m;
        }
        return r - 1;
    };
};

#endif
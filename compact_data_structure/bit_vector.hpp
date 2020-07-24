#ifndef BIT_VECTOR_HPP
#define BIT_VECTOR_HPP

#include <cstdint>
#include <vector>
#include <string>
#include "../bit/pop_count.hpp"

struct BitVector {
    using u64 = uint64_t;
    using u32 = uint32_t;
    using u8 = uint8_t;

    std::vector<u32> bit;
    std::vector<u32> chunk;

    BitVector() = default;
    explicit BitVector(int len) : bit((len + 31) / 32, 0), chunk((len + 31) / 32, 0){};
    BitVector(std::vector<bool> v) : bit((v.size() + 31) / 32, 0), chunk((v.size() + 31) / 32, 0) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i]) set(i);
        }
    };
    BitVector(std::string s) : bit((s.size() + 31) / 32, 0), chunk((s.size() + 31) / 32, 0) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') set(i);
        }
    };

    bool operator[] (int k) {
        return bool((bit[k / 32] >> (k & 31)) & 1);
    };

    void set(int k) {
        bit[k / 32] |= 1u << (k & 31);
    };
    void build() {
        for (int i = 1; i < size(); i++) {
            chunk[i] = chunk[i - 1] + popcnt32(bit[i - 1]);
        }
    };

    int size() {
        return bit.size();
    };

    // count number of 1 in [0, k)
    int rank1(int k) {
        return chunk[k / 32] +
        popcnt32(bit[k / 32] & ~((~0u) << (k & 31)));
    };
    // count number of 0 in [0, k)
    int rank0(int k) {
        return k - rank1(k);
    };
    int select1(int k) {
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
    int select0(int k) {
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
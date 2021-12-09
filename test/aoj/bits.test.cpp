#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include <bits/stdc++.h>

#include "../../bit/clz.hpp"
#include "../../bit/ctz.hpp"
#include "../../bit/lsb.hpp"
#include "../../bit/msb.hpp"
#include "../../bit/pop_count.hpp"
#include "../../util/xorshift.hpp"

#define _overload(_1, _2, _3, _4, name, ...) name
#define _rep1(Itr, N) _rep3(Itr, 0, N, 1)
#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)
#define _rep3(Itr, a, b, step) for (i64 Itr = a; Itr < b; Itr += step)
#define repeat(...) _overload(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)
#define rep(...) repeat(__VA_ARGS__)

#define ALL(X) begin(X), end(X)

using namespace std;
using i64 = int64_t;
using u64 = uint64_t;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    xorshift64 rnd64(1);
    xorshift32 rnd32(1);

    rep(i, 1 << 25) {
        u64 bit64 = rnd64();
        unsigned bit32 = rnd32();

        assert(ctz32_(bit32) == __builtin_ctz(bit32));
        assert(ctz64(bit64) == __builtin_ctzll(bit64));

        assert(clz32_(bit32) == __builtin_clz(bit32));
        assert(clz64(bit64) == __builtin_clzll(bit64));

        assert(popcnt32_(bit32) == __builtin_popcount(bit32));
        assert(popcnt64_(bit64) == __builtin_popcountll(bit64));

        assert(msb32_(bit32) == 1u << (31 - __builtin_clz(bit32)));
        assert(msb64_(bit64) == 1ull << (63 - __builtin_clzll(bit64)));
    }

    rep(i, 32) {
        assert(msb32_(rnd32() | (1u << i)) >= 1u << i);
        assert(msb64_(rnd64() | (1ull << i)) >= 1ull << i);

        assert(ctz32_(1u << i) == i);
        assert(ctz32_(3u << i) == i);

        assert(ctz32_(21u << i) == i);
        assert(clz32_(1u << i) == 31 - i);
    }
    rep(i, 64) {
        assert(msb64_(rnd32() | (1ull << i)) >= 1ull << i);
        assert(msb64_(rnd64() | (1ull << i)) >= 1ull << i);

        assert(ctz64_(1ull << i) == i);
        assert(ctz64_(3ull << i) == i);

        assert(ctz64_(21ull << i) == i);
        assert(clz64_(1ull << i) == 63 - i);
    }

    cout << "Hello World" << endl;
    return 0;
}
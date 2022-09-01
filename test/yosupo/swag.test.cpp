#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
// header file section
#include <algorithm>
#include <bitset>
#include <cfloat>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include "../../deque/sliding_window.hpp"

using namespace std;
using llong = long long;

// const llong mod = 998244353;
#define mod (998244353ll)
SlidingWindow<pair<llong, llong>> swag([](auto l, auto r) {
    pair<llong, llong> ret;
    ret.first = l.first * r.first;
    ret.second = l.first * r.second + l.second;
    ret.first %= mod;
    ret.second %= mod;
    return ret;
});

int main() {
    llong q;
    llong com;
    llong a, b;
    llong x;

    cin >> q;

    while (q--) {
        cin >> com;

        if (com == 0) {
            cin >> a >> b;
            swag.push_front({a, b});
        } else if (com == 1) {
            swag.pop_back();
        } else if (com == 2) {
            cin >> x;

            if (swag.empty()) {
                cout << x << '\n';
            } else {
                auto f = swag.fold();
                cout << (f.first * x + f.second) % mod << '\n';
            }
        }
    }
    return 0;
};

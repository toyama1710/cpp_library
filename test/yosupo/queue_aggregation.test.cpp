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

#include "../../queue/queue_aggregation.hpp"

using namespace std;
using llong = long long;

// const llong mod = 998244353;
#define mod (998244353ll)
QueueAggregation<pair<llong, llong>> swag([](auto l, auto r) {
    pair<llong, llong> ret;
    ret.first = r.first * l.first;
    ret.second = r.first * l.second + r.second;
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
            swag.push({a, b});
        } else if (com == 1) {
            swag.pop();
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

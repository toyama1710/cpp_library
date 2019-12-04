#include <iostream>
#include <cstdio>
#include <vector>
#include <iterator>
using namespace std;
using llong = long long;

//===
template <class T>
struct PartiallyPersistentArray {
    int turn;
    vector<vector<pair<int, T>>> arr;
    const size_t sz;

    PartiallyPersistentArray(size_t nmemb, T v): sz(nmemb) {
        turn = 0;
        arr.resize(sz, vector<pair<int, T> >(1, {0, v}));
    };

    template<class InputIterator>
    PartiallyPersistentArray(InputIterator first, InputIterator last):
        sz(distance(first, last))
    {
        turn = 0;
        arr.reserve(sz);
        for (InputIterator i = first; i != last; i++) {
            arr.push_back(vector<pair<int, T>>(1, {0, *i}));
        }
    };

    void set(int k, T v) {
        arr[k].push_back({++turn, v});
    };

    T get(int t, int k) {
        int valid = 0;
        int invalid = arr[k].size();
        int mid;

        while (invalid - valid > 1) {
            mid = (valid + invalid) / 2;

            if (t <= arr[k][mid].first) valid = mid;
            else invalid = mid;
        }

        return arr[k][valid];
    };
};
//===


int main() {

    return 0;
}

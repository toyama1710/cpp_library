#define IGNORE
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdint>
#include <array>
using namespace std;
using llong = long long;

//===
// #include <cstdint>
// #include <array>
template<class T, size_t N, size_t BlockSize = 64>
struct SparseArray {
    array<T *, (N + BlockSize - 1) / BlockSize> ptr;

    SparseArray() {
        ptr.fill(nullptr);
    };

    ~SparseArray() {
        clear();
    };

    void clear() {
        for (auto p:ptr) delete p;
        ptr.fill(nullptr);
    };

    T& operator [](size_t k) {
        if (!ptr[k / BlockSize]) ptr[k / BlockSize] = new T[BlockSize];
        return &((ptr[k / BlockSize])[k % BlockSize]);
    };
};
//===

int main() {
    llong n;
    SparseArray<llong, 100> arr;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << ' ';
    }

    return 0;
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdint>
#include <array>

//===
// #include <cstdint>
// #include <array>
template<class T, size_t N, size_t BlockSize = 64>
struct SparseArray {
    std::array<T *, (N + BlockSize - 1) / BlockSize> ptr;

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

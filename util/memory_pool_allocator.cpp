#include <iostream>
#include <vector>
#include <cassert>
#include <numeric>
#include <cstdint>
using namespace std;

//===

// for use: speed up tree (ex. persistent data structure)
template<class T>
struct MemoryPoolAllocator {
    vector<T *> addr;
    vector<T> mem;
    size_t ptr;

    MemoryPoolAllocator(size_t n) {
        mem.resize(n);
        addr.resize(n);

        for (int i = 0; i < n; i++) {
            addr[i] = &(mem[i]);
        }
    };

    T *allocate(size_t n) {
        assert(n == 1);
        return addr[ptr++];
    };

    void deallocate(T *p, size_t n) {
        assert(n == 1);
        addr[--ptr] = p;
    };
};

//===

int main() {
}

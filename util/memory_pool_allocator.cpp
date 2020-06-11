#ifndef MEMORY_POOL_ALLOCATOR_HPP
#define MEMORY_POOL_ALLOCATOR_HPP

#include <vector>
#include <cassert>
#include <numeric>
#include <cstdint>

//===

// for use: speed up tree (ex. persistent data structure)
template<class T>
struct MemoryPoolAllocator {
    std::vector<T *> addr;
    std::vector<char> mem;
    size_t ptr;

    MemoryPoolAllocator(size_t n) {
        ptr = 0;
        mem.resize(sizeof(T) * n);
        addr.resize(n);

        for (int i = 0; i < n; i++) {
            addr[i] = &(mem[i * sizeof(T)]);
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
#endif

#ifndef MEMORY_POOL_ALLOCATOR_HPP
#define MEMORY_POOL_ALLOCATOR_HPP

#include <cassert>
#include <array>
#include <numeric>
#include <cstdint>

//===

// for use: speed up (ex. persistent data structure)
template<class T, size_t sz>
struct MemoryPoolAllocator {
    using value_type = T;
    std::array<T *, sz> addr;
    std::array<char, sizeof(T) * sz> mem;
    size_t ptr;

    MemoryPoolAllocator() {
        ptr = 0;

        for (int i = 0; i < sz; i++) {
            addr[i] = &(mem[i * sizeof(T)]);
        }
    };

    template<class U>
    struct rebind {
        using other = MemoryPoolAllocator<U, sz>;
    };

    T *allocate(size_t n) {
        assert(n == 1);
        return addr[ptr++];
    };

    void deallocate(T *p, size_t n) {
        assert(n == 1);
        addr[--ptr] = p;
    };

    int max_size() {
        return 1;
    };
};

//===
#endif

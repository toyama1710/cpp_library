#include <iostream>
#include <vector>
using namespace std;

template<class T, class Compare = less<T>>
struct SparseTable {

    bool builded = false;
    size_t n;
    const Compare cmp;
    vector<T> elements;
    vector<vector<T>> table;
    vector<size_t> log2;

    SparseTable(size_t n, Compare &f = Compare(), T v = T()):
        n(n), log2(n + 1, v), cmp(f)
    {
        for (size_t i = 2; i <= n; i++) log2[i] = log2[i / 2] + 1;
        elements.assign(n, v);
        table.assign(log2[n], vector<int>(n));
    }

    template<class InputIterator>
    SparseTable(InputIterator first, InputIterator last,
                Compare &f = Compare()):
        SparseTable(distance(first, last), f, *first)
    {
        build();
        //table = vector<vector<T>>(logn, vector<T>(first, last));
    }

    void build(void)
    {
        for (int i = 0; i < n; i++) table[0][i] = i;
        
        for (int i = 0; i < log2[n]; i++) {
            size_t w = 1 << i;
            for (int j = 0; j + (w * 2) <= n; j++) {
                size_t l = table[i][j];
                size_t r = table[i][j + w];

                if (cmp(elements[l], elements[r])) table[i + 1][j] = l;
                else table[i + 1][j] = r;
            }
        }

        builded = true;
    }

    void set(size_t k, T dat)
    {
        elements[k] = dat;
        builded = false;
        return;
    }

    //[l, r)
    T get(size_t l, size_t r)
    {
        if (!builded) build();

        size_t k = log2[r - l];
        l = table[k][l];
        r = table[k][r - (1 << k)];

        if (cmp(elements[l], elements[r])) return elements[l];
        else return elements[r];
    }

    size_t size() { return n; }

    T operator[] (const size_t k)
    {
        return elements[k];
    }
};

int main()
{
}

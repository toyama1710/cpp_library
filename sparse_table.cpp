#include <iostream>
#include <functional>
#include <vector>
using namespace std;

//===
template<class T, class Compare = less<T>>
struct SparseTable {

    bool builded = false;
    const int n;
    const Compare cmp;
    vector<T> elements;
    vector<vector<int>> table;
    vector<size_t> log2;

    SparseTable():n(0){}
    SparseTable(int n, T v = T(), const Compare &f = Compare()):
        n(n), log2(n + 1), elements(n, v), cmp(f)
    {
        for (int i = 2; i <= n; i++) log2[i] = log2[i / 2] + 1;
        table.assign(log2[n] + 1, vector<int>(n));
    }

    template<class InputIterator>
    SparseTable(InputIterator first, InputIterator last,
                const Compare &f = Compare()):
        n(distance(first, last)), log2(n + 1), elements(first, last), cmp(f)
    {
        for (int i = 2; i <= n; i++) log2[i] = log2[i / 2] + 1;
        table.assign(log2[n] + 1, vector<int>(n));
        build();
        //table = vector<vector<T>>(logn, vector<T>(first, last));
    }

    void build(void)
    {
        for (int i = 0; i < n; i++) table[0][i] = i;
        
        for (int i = 0; i < log2[n]; i++) {
            int w = 1 << i;
            for (int j = 0; j + (w * 2) <= n; j++) {
                int l = table[i][j];
                int r = table[i][j + w];

                if (cmp(elements[l], elements[r])) table[i + 1][j] = l;
                else table[i + 1][j] = r;
            }
        }

        builded = true;
    }

    void set(int k, T dat)
    {
        elements[k] = dat;
        builded = false;
        return;
    }

    //[l, r)
    T query(int l, int r)
    {
        if (!builded) build();

        int k = log2[r - l];
        l = table[k][l];
        r = table[k][r - (1 << k)];

        if (cmp(elements[l], elements[r])) return elements[l];
        else return elements[r];
    }

    int size() { return n; }

    T operator[] (const int k)
    {
        return elements[k];
    }
};
//===

int RMQ(void)
{
    using ll = long long;

    ll n, q;
    ll com, x, y;
    vector<ll> arr;

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> x;
        arr.push_back(x);
    }

    cout << "building..." << endl;
    SparseTable<ll, greater<>> st(arr.begin(), arr.end());
    cout << "done." << endl;
    while (q--) {
        cin >> x >> y;
        cout << st.query(x, y) << endl;
    }

    return 0;
}

int main()
{
    //return RMQ();
}

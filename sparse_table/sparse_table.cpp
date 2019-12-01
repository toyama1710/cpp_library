#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
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
        n(n), log2(n + 1), elements(n), cmp(f)
    {
        for (int i = 2; i <= n; i++) log2[i] = log2[i / 2] + 1;
        elements.assign(n, v);
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

    void build(void) {
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

    void set(int k, T dat) {
        elements[k] = dat;
        builded = false;
        return;
    }

    //[l, r)
    T query(int l, int r) {
        if (!builded) build();

        int k = log2[r - l];
        l = table[k][l];
        r = table[k][r - (1 << k)];

        if (cmp(elements[l], elements[r])) return elements[l];
        else return elements[r];
    }

    int size() { return n; }

    T operator[] (const int k) { return elements[k]; }
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

int PCK2014_pre_8(void)
{
    using ll = long long;
    struct Star{ ll x, y, b; };
    auto scmp = [](const Star &x, const Star &y) {
                    if (x.b < y.b) return true;
                    else return false;
                };

    ll ans = 0;
    ll n, d;
    vector<Star> s;
    
    cin >> n >> d;
    s = vector<Star>(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i].x >> s[i].y >> s[i].b;
    }

    sort(s.begin(), s.end(), scmp);
    
    SparseTable<ll> minX(n, 0);
    SparseTable<ll, greater<>> maxX(n, 0);
    SparseTable<ll> minY(n, 0);
    SparseTable<ll, greater<>> maxY(n, 0);

    for (int i = 0; i < n; i++) {
        minX.set(i, s[i].x);
        maxX.set(i, s[i].x);

        minY.set(i, s[i].y);
        maxY.set(i, s[i].y);
    }

    for (int i = 0; i < n; i++) {
        ll l = i;
        ll r = upper_bound(s.begin(), s.end(), (Star){0, 0, s[i].b + d}, scmp)
        - s.begin();

        ll x = maxX.query(l, r) - minX.query(l, r);
        ll y = maxY.query(l, r) - minY.query(l, r);

        ans = max(ans, x * y);
    }

    cout << ans << endl;

    return 0;
}

int main()
{
    //return RMQ();
    return PCK2014_pre_8();
}

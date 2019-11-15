#include <iostream>
#include <cstdio>
using namespace std;
using llong = long long;

//===
template<class Integer>
inline Integer lsb(Integer bits) {
    return bits & (~bits + 1);
}
//===

int main() {
    int a;
    llong b;
    unsigned c;

    cin >> a >> b >> c;
    cout << lsb(a) << ' ' << lsb(b) << ' ' << lsb(c) << endl;

    return 0;
}

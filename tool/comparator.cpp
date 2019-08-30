#include <functional>
using namespace std;

//===
template<typename T,
         typename Equal = equal_to<T>,
         typename Less = less<T>,
         typename Greater = greater<T>>
struct Comparator {
    const Equal eq();
    const Less le();
    const Greater gr();

    int operator ()(const T &l, const T &r) {
        if (le(l, r)) return -1;
        if (eq(l, r)) return 0;
        if (gr(l, r)) return 1;
    }
};
//===

int main() {
    return 0;
}

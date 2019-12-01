#include <iostream>
#include <functional>
#include <vector>
#include <memory>
using namespace std;
using llong = long long;

//===
template<class T, class Alloc = allocator<T> >
struct PersitentArray {
    using Traits = allocator_traits<Alloc>;
    struct Leaf {
        T dat;
    };
    
    using NodePointer = union self {
        Leaf *d;
        self *u;
    };
    struct Node {
        NodePointer ch[2] = {}; // 0:left, 1:right
    };

    Traits alc;
    Node *root;
    
    PersitentArray(size_t size) {
    };
    
    template<class InputIterator>
    PersitentArray(InputIterator first, InputIterator last) {
    };
};
//===

int main() {

    return 0;
}

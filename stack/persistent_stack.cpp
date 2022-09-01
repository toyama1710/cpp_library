#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>
using namespace std;
using llong = long long;

//===
template <class T, template <class> class Alloc = allocator>
struct PersistentStack {
    struct Node {
        T d;
        Node *next = nullptr;
    };
    using Traits = allocator_traits<Alloc<Node> >;
    static Alloc<Node> alc;

    Node *head = nullptr;

    PersistentStack current_stack() {
        return PersistentStack(head);
    };

    T top() {
        return head->d;
    };

    void push(T d) {
        Node *p = Traits::allocate(alc, 1);
        Traits::construct(alc, p, d, head);
        head = p;
    };

    void pop(T d) {
        head = head->next;
    };

    ~PersistentStack() {
        Node *p;
        while (head != nullptr) {
            p = head->next;
            Traits::deallocate(alc, head, 1);
            head = p;
        }
    };
};
//===

int main() {
    return 0;
}

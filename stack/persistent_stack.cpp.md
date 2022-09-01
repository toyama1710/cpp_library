---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"stack/persistent_stack.cpp\"\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <iostream>\n#include <memory>\nusing namespace std;\nusing\
    \ llong = long long;\n\n//===\ntemplate <class T, template <class> class Alloc\
    \ = allocator>\nstruct PersistentStack {\n    struct Node {\n        T d;\n  \
    \      Node *next = nullptr;\n    };\n    using Traits = allocator_traits<Alloc<Node>\
    \ >;\n    static Alloc<Node> alc;\n\n    Node *head = nullptr;\n\n    PersistentStack\
    \ current_stack() {\n        return PersistentStack(head);\n    };\n\n    T top()\
    \ {\n        return head->d;\n    };\n\n    void push(T d) {\n        Node *p\
    \ = Traits::allocate(alc, 1);\n        Traits::construct(alc, p, d, head);\n \
    \       head = p;\n    };\n\n    void pop(T d) {\n        head = head->next;\n\
    \    };\n\n    ~PersistentStack() {\n        Node *p;\n        while (head !=\
    \ nullptr) {\n            p = head->next;\n            Traits::deallocate(alc,\
    \ head, 1);\n            head = p;\n        }\n    };\n};\n//===\n\nint main()\
    \ {\n    return 0;\n}\n"
  code: "#include <cstdio>\n#include <cstdlib>\n#include <iostream>\n#include <memory>\n\
    using namespace std;\nusing llong = long long;\n\n//===\ntemplate <class T, template\
    \ <class> class Alloc = allocator>\nstruct PersistentStack {\n    struct Node\
    \ {\n        T d;\n        Node *next = nullptr;\n    };\n    using Traits = allocator_traits<Alloc<Node>\
    \ >;\n    static Alloc<Node> alc;\n\n    Node *head = nullptr;\n\n    PersistentStack\
    \ current_stack() {\n        return PersistentStack(head);\n    };\n\n    T top()\
    \ {\n        return head->d;\n    };\n\n    void push(T d) {\n        Node *p\
    \ = Traits::allocate(alc, 1);\n        Traits::construct(alc, p, d, head);\n \
    \       head = p;\n    };\n\n    void pop(T d) {\n        head = head->next;\n\
    \    };\n\n    ~PersistentStack() {\n        Node *p;\n        while (head !=\
    \ nullptr) {\n            p = head->next;\n            Traits::deallocate(alc,\
    \ head, 1);\n            head = p;\n        }\n    };\n};\n//===\n\nint main()\
    \ {\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: stack/persistent_stack.cpp
  requiredBy: []
  timestamp: '2022-09-01 14:18:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: stack/persistent_stack.cpp
layout: document
redirect_from:
- /library/stack/persistent_stack.cpp
- /library/stack/persistent_stack.cpp.html
title: stack/persistent_stack.cpp
---

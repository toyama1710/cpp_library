#ifndef REVERSE_CMP_HPP
#define REVERSE_CMP_HPP

template <class T>
struct RevCmp {
    T val;

    RevCmp(T val) : val(val){};

    bool operator<(const RevCmp &rhs) const { return rhs.val < val; };
    bool operator>(const RevCmp &rhs) const { return val < rhs.val; };
    bool operator==(const RevCmp &rhs) const {
        return !(val < rhs.val || rhs.val < val);
    };
    bool operator!=(const RevCmp &rhs) const {
        return val < rhs.val || rhs.val < val;
    };
    bool operator<=(const RevCmp &rhs) const {
        return *this < rhs || *this == rhs;
    };
    bool operator>=(const RevCmp &rhs) const {
        return *this > rhs || *this == rhs;
    };

    RevCmp &operator=(const RevCmp &rhs) {
        val = rhs.val;
        return *this;
    };

    T value() const { return val; };
};

#endif
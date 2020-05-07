//===
template<class T = int>
struct MonoidSnippet {
    using value_type = T;
    inline static T identity() {
    };
    inline static T operation(const T a, const T b) {
    };
};
//===

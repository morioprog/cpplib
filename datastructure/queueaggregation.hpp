/**
* @brief Queue Aggregation
* @docs docs/datastructure/queueaggregation.md
*/

template <typename T>
struct QueueAggregation {
    using F = function<T(T, T)>;
    stack<pair<T, T>> st_f, st_b;  // {val, sum}
    const F func;
    const T IDENT;
    QueueAggregation(const F f, const T IDENT)
        : func(f), IDENT(IDENT) {
        st_f.emplace(IDENT, IDENT);
        st_b.emplace(IDENT, IDENT);
    }
    // remove sentinel
    int size() const { return (int)st_f.size() + (int)st_b.size() - 2; }
    bool empty() const { return size() == 0; }
    T query() {
        return func(st_f.top().second, st_b.top().second);
    }
    void emplace(const T &x) {
        T merged = func(st_b.top().second, x);
        st_b.emplace(x, merged);
    }
    void pop() {
        assert(not empty());
        if (st_f.size() == 1) {  // <=> st_f.empty()
            st_f.emplace(st_b.top().first, st_b.top().first);
            st_b.pop();
            while (st_b.size() != 1) {
                T merged = func(st_b.top().first, st_f.top().second);
                st_f.emplace(st_b.top().first, merged);
                st_b.pop();
            }
        }
        st_f.pop();
    }
};

/**
* @brief LR Priority Queue
* @docs docs/datastructure/lrprique.md
*/

template <typename T>
struct LRPrique {
    using F = function<int(int)>;
    const F f;
    const T err;
    priority_queue<T> L;
    priority_queue<T, vector<T>, greater<>> R;
    int L_sz, R_sz;
    T L_sum, R_sum;
    // f(sz) -> size of L
    // e.g.) median : [](int sz) -> int { return (sz + 1) / 2; }
    LRPrique(F f, T err = numeric_limits<T>::max())
        : f(f), err(err), L_sz(0), R_sz(0), L_sum(0), R_sum(0) {}
    void L_push(T x) {
        ++L_sz;
        L_sum += x;
        L.emplace(x);
    }
    void R_push(T x) {
        ++R_sz;
        R_sum += x;
        R.emplace(x);
    }
    T L_pop() {
        T ret = L.top();
        L.pop();
        --L_sz;
        L_sum -= ret;
        return ret;
    }
    T R_pop() {
        T ret = R.top();
        R.pop();
        --R_sz;
        R_sum -= ret;
        return ret;
    }
    void emplace(T x) {
        if (R.empty() or R.top() > x)
            L_push(x);
        else
            R_push(x);
    }
    void flatten() {
        int gL_sz = f(L_sz + R_sz);
        while (L.size() < gL_sz) {
            T tp = R_pop();
            L_push(tp);
        }
        while (L.size() > gL_sz) {
            T tp = L_pop();
            R_push(tp);
        }
    }
    T get() {
        int gL_sz = f(L_sz + R_sz);
        if (gL_sz > L_sz + R_sz) return err;
        flatten();
        return L.top();
    }
};

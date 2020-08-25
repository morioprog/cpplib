/**
* @brief LR MultiSet
* @docs docs/datastructure/lrmultiset.md
*/

template <typename T>
struct LRMultiSet {
    using F = function<int(int)>;
    const F f;
    const T err;
    multiset<T> L, R;
    int L_sz, R_sz;
    T L_sum, R_sum;
    // f(sz) -> size of L
    // e.g.) median : [](int sz) -> int { return (sz + 1) / 2; }
    LRMultiSet(F f, T err = numeric_limits<T>::max())
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
        T ret = L_get_max();
        L.erase(prev(L.end()));
        --L_sz;
        L_sum -= ret;
        return ret;
    }
    T R_pop() {
        T ret = R_get_min();
        R.erase(R.begin());
        --R_sz;
        R_sum -= ret;
        return ret;
    }
    T L_get_min() {
        if (L.empty()) return err;
        return *L.begin();
    }
    T L_get_max() {
        if (L.empty()) return err;
        return *prev(L.end());
    }
    T R_get_min() {
        if (R.empty()) return err;
        return *R.begin();
    }
    T R_get_max() {
        if (R.empty()) return err;
        return *prev(R.end());
    }
    void erase(T x) {
        auto itr_l = L.find(x);
        if (itr_l != L.end()) {
            --L_sz;
            L_sum -= x;
            L.erase(itr_l);
            return;
        }
        auto itr_r = R.find(x);
        if (itr_r != R.end()) {
            --R_sz;
            R_sum -= x;
            R.erase(itr_r);
            return;
        }
        assert(false);
    }
    void emplace(T x) {
        if (R.empty() or R_get_min() > x)
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
        return L_get_max();
    }
};

/**
* @brief セグメント木
* @docs docs/datastructure/segmenttree/segmenttree.md
*/

template <typename T, typename F>
struct SegmentTree {
    int N;
    const int sz;
    const T ID;
    const F f;
    vector<T> cbt;
    SegmentTree(int n, T ID, F func)
        : sz(n), ID(ID), f(func) { init(sz); }
    SegmentTree(vector<T> V, T ID, F func)
        : sz(V.size()), ID(ID), f(func) {
        init(sz);
        for (int i = 0; i < sz; ++i)
            cbt[i + N] = V[i];
        for (int i = N - 1; i >= 1; --i)
            cbt[i] = f(cbt[i << 1 | 0], cbt[i << 1 | 1]);
    }
    void init(int n) {
        N = 1;
        while (N < n) N <<= 1;
        cbt.assign(N << 1, ID);
    }
    void update(int idx, T val) {
        assert(0 <= idx and idx < sz);
        idx += N;
        cbt[idx] = val;
        while (idx >>= 1) cbt[idx] = f(cbt[idx << 1 | 0], cbt[idx << 1 | 1]);
    }
    T query(int l, int r) {
        assert(0 <= l and l <= r and r <= sz);
        T ret_l = ID, ret_r = ID;
        l += N, r += N;
        while (l < r) {
            if (l & 1) ret_l = f(ret_l, cbt[l++]);
            if (r & 1) ret_r = f(cbt[--r], ret_r);
            l >>= 1, r >>= 1;
        }
        return f(ret_l, ret_r);
    }
    T query_all() { return cbt[1]; }
    template <typename CF>
    int rightmost(CF check, int l = 0) {
        assert(0 <= l and l <= sz);
        assert(check(ID));
        if (l == sz) return sz;
        l += N;
        T acc = ID;
        do {
            while (l % 2 == 0) l >>= 1;
            if (not check(f(acc, cbt[l]))) {
                while (l < N) {
                    l = 2 * l;
                    if (check(f(acc, cbt[l]))) acc = f(acc, cbt[l++]);
                }
                return l - N;
            }
            acc = f(acc, cbt[l++]);
        } while ((l & -l) != l);
        return sz;
    }
    template <typename CF>
    int leftmost(CF check, int r = INT_MIN) {
        if (r == INT_MIN) r = sz;
        assert(0 <= r and r <= sz);
        assert(check(ID));
        if (r == 0) return 0;
        r += N;
        T acc = ID;
        do {
            --r;
            while (r > 1 and (r % 2)) r >>= 1;
            if (not check(f(cbt[r], acc))) {
                while (r < N) {
                    r = 2 * r + 1;
                    if (check(f(cbt[r], acc))) acc = f(cbt[r--], acc);
                }
                return r + 1 - N;
            }
            acc = f(cbt[r], acc);
        } while ((r & -r) != r);
        return 0;
    }
    T const& operator[](int idx) const { return cbt[idx + N]; }
    void print() {
        for (int i = 1; i < 2 * N; ++i) {
            cerr << cbt[i] << ' ';
            if (!(i & (i + 1))) cerr << endl;
        }
    }
};

template <typename T, typename F>
auto make_segment_tree(int N, T ID, F func) {
    return SegmentTree<T, F>(N, ID, func);
}
template <typename T, typename F>
auto make_segment_tree(vector<T> V, T ID, F func) {
    return SegmentTree<T, F>(V, ID, func);
}

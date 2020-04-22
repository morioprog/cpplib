/**
* @brief セグメント木
* @docs docs/datastructure/segmenttree/segmenttree.md
*/

template<typename T> struct SegmentTree {
    using F = function<T(T, T)>;
    vector<T> seg;
    int sz;
    const F func;
    const T IDENT;
    SegmentTree() {}
    SegmentTree(int n, const F f, const T &ID) : func(f), IDENT(ID) {
        sz = 1; while (sz < n) sz <<= 1;
        seg.assign(2 * sz - 1, IDENT);
    }
    SegmentTree(vector<T> v, const F f, const T &ID) : func(f), IDENT(ID) {
        int n = v.size();
        sz = 1; while (sz < n) sz <<= 1;
        seg.assign(2 * sz - 1, IDENT);
        for (int i = 0; i < n; ++i) seg[i + sz - 1] = v[i];
        for (int i = sz - 2; i >= 0; --i) seg[i] = func(seg[2 * i + 1], seg[2 * i + 2]);
    }
    void update(int k, T x) {
        k += sz - 1;
        seg[k] = x;
        while (k > 0) {
            k = (k - 1) / 2;
            seg[k] = func(seg[2 * k + 1], seg[2 * k + 2]);
        }
    }
    void add(int k, T x) {
        k += sz - 1;
        seg[k] += x;
        while (k > 0) {
            k = (k - 1) / 2;
            seg[k] = func(seg[2 * k + 1], seg[2 * k + 2]);
        }
    }
    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = sz;
        if (r <= a || l >= b) return IDENT;
        if (l >= a && r <= b) return seg[k];
        T f_l = query(a, b, 2 * k + 1, l, (l + r) / 2);
        T f_r = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return func(f_l, f_r);
    }
    void print() {
        for (int i = 0; i < 2 * sz - 1; ++i) {
            cerr << seg[i] << ' ';
            if (!((i + 2) & (i + 1))) cerr << endl;
        }
    }
};

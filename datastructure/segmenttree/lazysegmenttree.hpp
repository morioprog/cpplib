/**
* @brief 遅延セグメント木
* @docs docs/datastructure/segmenttree/lazysegmenttree.md
*/

template <typename M, typename OM, typename F, typename G, typename H, typename P>
struct LazySegmentTree {
    int sz;
    F f;
    G g;
    H h;
    P p;
    const M ID_M;
    const OM ID_OM;
    vector<M> dat;
    vector<OM> laz;
    LazySegmentTree(int n, M ID_M, OM ID_OM, F f, G g, H h, P p)
        : ID_M(ID_M), ID_OM(ID_OM), f(f), g(g), h(h), p(p) { build(n); }
    LazySegmentTree(const vector<M> &v, M ID_M, OM ID_OM, F f, G g, H h, P p)
        : ID_M(ID_M), ID_OM(ID_OM), f(f), g(g), h(h), p(p) {
        int n = v.size();
        build(n);
        for (int i = 0; i < n; ++i) dat[i + sz - 1] = v[i];
        for (int i = sz - 2; i >= 0; --i) dat[i] = f(dat[2 * i + 1], dat[2 * i + 2]);
    }
    void build(int n) {
        sz = 1;
        while (sz < n) sz <<= 1;
        dat.assign(2 * sz - 1, ID_M);
        laz.assign(2 * sz - 1, ID_OM);
    }
    void eval(int len, int k) {
        if (laz[k] == ID_OM) return;
        if (2 * k + 1 < 2 * sz - 1) {
            laz[2 * k + 1] = h(laz[2 * k + 1], laz[k]);
            laz[2 * k + 2] = h(laz[2 * k + 2], laz[k]);
        }
        dat[k] = g(dat[k], p(laz[k], len));
        laz[k] = ID_OM;
    }
    M update(int a, int b, OM x, int k, int l, int r) {
        eval(r - l, k);
        if (r <= a or b <= l) return dat[k];
        if (a <= l and r <= b) {
            laz[k] = h(laz[k], x);
            return g(dat[k], p(laz[k], r - l));
        }
        return dat[k] = f(update(a, b, x, 2 * k + 1, l, (l + r) / 2),
                          update(a, b, x, 2 * k + 2, (l + r) / 2, r));
    }
    M update(int a, int b, OM x) {
        return update(a, b, x, 0, 0, sz);
    }
    M query(int a, int b, int k, int l, int r) {
        eval(r - l, k);
        if (r <= a or b <= l) return ID_M;
        if (a <= l and r <= b) return dat[k];
        M vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        M vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return f(vl, vr);
    }
    M query(int a, int b) {
        return query(a, b, 0, 0, sz);
    }
    M operator[](const int &k) {
        return query(k, k + 1);
    }
    void print() {
        for (int i = 0; i < sz; ++i) cerr << query(i, i + 1) << ' ';
        cerr << endl;
    }
};

template <typename M, typename OM, typename F, typename G, typename H, typename P>
auto make_segtree(int n, M ID_M, OM ID_OM, F f, G g, H h, P p) {
    return LazySegmentTree<M, OM, F, G, H, P>(n, ID_M, ID_OM, f, g, h, p);
}
template <typename M, typename OM, typename F, typename G, typename H, typename P>
auto make_segtree(vector<M> v, M ID_M, OM ID_OM, F f, G g, H h, P p) {
    return LazySegmentTree<M, OM, F, G, H, P>(v, ID_M, ID_OM, f, g, h, p);
}

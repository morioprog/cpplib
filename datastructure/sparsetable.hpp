/**
* @brief Sparse Table
* @docs docs/datastructure/sparsetable.md
*/

template <typename T>
struct SparseTable {
    vector<vector<T>> st;
    using F = function<T(T, T)>;
    const F f;
    SparseTable() {}
    SparseTable(const vector<T> &v, const F f)
        : f(f) {
        int b = 0, sz = v.size();
        while ((1 << b) <= sz) ++b;
        st.assign(b, vector<T>(1 << b));
        for (int i = 0; i < sz; ++i) st[0][i] = v[i];
        for (int i = 1; i < b; ++i) {
            for (int j = 0; j + (1 << i) <= (1 << b); ++j) {
                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    T query(const int l, const int r) const {
        int b = 31 - __builtin_clz(r - l);
        return f(st[b][l], st[b][r - (1 << b)]);
    }
};

/**
* @brief Binary Indexed Tree
* @docs docs/datastructure/binaryindexedtree.md
*/

template<typename T> struct BinaryIndexedTree {
    vector<T> data;
    BinaryIndexedTree(int sz) { data.assign(++sz, 0); }
    T sum(int k) {
        if (k < 0) return T(0);
        T ret = 0;
        for (++k; k > 0; k -= k & -k) ret += data[k];
        return (ret);
    }
    T sum(int l, int r) {
        assert(l <= r);
        return sum(r - 1) - sum(l - 1);
    }
    void add(int k, T x) {
        for (++k; k < data.size(); k += k & -k) data[k] += x;
    }
    int lower_bound(T w) {
        if (w <= 0) return 0;
        int n = data.size(), x = 0, r = 1;
        while (r < n) r <<= 1;
        for (int k = r; k > 0; k >>= 1) {
            if (x + k <= n and data[x + k] < w) {
                w -= data[x + k];
                x += k;
            }
        }
        return x + 1;
    }
};

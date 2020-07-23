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
};

/**
* @brief 1次元累積和
* @docs docs/datastructure/cumulativesum/cumulativesum.md
*/

template <typename T>
struct CumulativeSum {
    int sz;
    vector<T> data;
    CumulativeSum(const vector<T> &v, const T margin = 0)
        : sz(v.size()), data(1, margin) {
        for (int i = 0; i < sz; ++i) data.emplace_back(data[i] + v[i]);
    }
    T query(const int &l, const int &r) const {
        if (l >= r) return 0;
        return data[min(r, sz)] - data[max(l, 0)];
    }
    T operator[](const int &k) const {
        return query(k, k + 1);
    }
    void print() {
        for (int i = 0; i < sz; ++i) cerr << data[i] << ' ';
        cerr << endl;
    }
};

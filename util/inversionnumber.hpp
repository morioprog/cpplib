/**
* @brief 転倒数
* @docs docs/util/inversionnumber.md
*/

template <typename T>
long long inversion_number(vector<T> &v) {
    int sz = v.size();
    vector<T> rev, v_cp(v);
    sort(v_cp.begin(), v_cp.end());
    for (auto &e : v) rev.emplace_back(lower_bound(v_cp.begin(), v_cp.end(), e) - v_cp.begin());
    BinaryIndexedTree<T> bit(sz);
    long long ret = 0;
    for (int i = 0; i < sz; ++i) {
        ret += i - bit.sum(rev[i]);
        bit.add(rev[i], 1);
    }
    return ret;
}

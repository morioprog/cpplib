/**
* @brief 座標圧縮
* @docs docs/util/compress.md
*/

template<typename T>
pair<vector<T>, map<T, int>> compress(vector<T> ord) {
    vector<T> com(ord);
    map<T, int> rev;
    sort(com.begin(), com.end());
    com.erase(unique(com.begin(), com.end()), com.end());
    for (int i = 0; i < com.size(); ++i) rev[com[i]] = i;
    vector<T> ret; for (auto& e: ord) ret.emplace_back(rev[e]);
    return make_pair(ret, rev);
}

/**
* @brief ランレングス圧縮 (groupby)
* @docs docs/util/groupby.md
*/

template <typename Container>
auto groupby(const Container &vec) {
    assert(vec.size() != 0);
    vector<pair<remove_const_t<remove_reference_t<decltype(vec.front())>>, int>> ret;
    int piv = -1;
    for (auto &e : vec) {
        if (piv == -1 or ret[piv].first != e)
            ++piv, ret.emplace_back(make_pair(e, 1));
        else
            ++(ret[piv].second);
    }
    return ret;
}

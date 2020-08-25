/**
* @brief 区間をmapで管理するやつ
* @note 閉区間であることに注意
* @docs docs/datastructure/segmentmap.md
* @see https://satanic0258.github.io/snippets/data-structure/SegmentMap.html
*/

struct SegmentMap : public map<long long, long long> {
    bool flg_merge;
    SegmentMap(bool flg_merge = true)
        : flg_merge(flg_merge) {}
    auto get(long long p) const {
        auto itr = upper_bound(p);
        if (itr == begin() or (--itr)->second < p) return end();
        return itr;
    }
    void insert(long long l, long long r) {
        auto itr_l = upper_bound(l), itr_r = upper_bound(r + flg_merge);
        if (itr_l != begin()) {
            if ((--itr_l)->second < l - flg_merge) ++itr_l;
        }
        if (itr_l != itr_r) {
            l = min(l, itr_l->first);
            r = max(r, prev(itr_r)->second);
            erase(itr_l, itr_r);
        }
        (*this)[l] = r;
    }
    void remove(long long l, long long r) {
        auto itr_l = upper_bound(l), itr_r = upper_bound(r);
        if (itr_l != begin()) {
            if ((--itr_l)->second < l) ++itr_l;
        }
        if (itr_l == itr_r) return;
        int tl = min(l, itr_l->first), tr = max(r, prev(itr_r)->second);
        erase(itr_l, itr_r);
        if (tl < l) (*this)[tl] = l - 1;
        if (r < tr) (*this)[r + 1] = tr;
    }
    bool same(long long p, long long q) const {
        const auto&& itr = get(p);
        return itr != end() and itr->first <= q and q <= itr->second;
    }
};

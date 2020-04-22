#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include "../../template/main.hpp"
#include "../../datastructure/segmenttree/segmenttreebeats.hpp"

signed main() {

    int N, Q;
    cin >> N >> Q;

    using lint = long long;
    vector<lint> A(N);
    for (auto& e: A) cin >> e;

    SegmentTreeBeats seg(A);

    while (Q--) {
        int q, l, r;  cin >> q >> l >> r;
        if (q == 0) {
            lint b; cin >> b;
            seg.update_min(l, r, b);
        } else if (q == 1) {
            lint b; cin >> b;
            seg.update_max(l, r, b);
        } else if (q == 2) {
            lint b; cin >> b;
            seg.add_val(l, r, b);
        } else {
            cout << seg.query_sum(l, r) << endl;
        }
    }

}

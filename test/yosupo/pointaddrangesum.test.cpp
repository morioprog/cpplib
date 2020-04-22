#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../template/main.hpp"
#include "../../datastructure/segmenttree/segmenttree.hpp"

signed main() {

    int N, Q;
    cin >> N >> Q;

    using T = long long;
    vector<T> A(N);
    for (auto& e: A) cin >> e;

    SegmentTree<T> seg(A, [](T a, T b){ return a + b; }, 0LL);

    while (Q--) {
        int q;  cin >> q;
        if (q == 0) {
            T p, x;   cin >> p >> x;
            seg.add(p, x);
        } else {
            int l, r;   cin >> l >> r;
            cout << seg.query(l, r) << endl;
        }
    }

}

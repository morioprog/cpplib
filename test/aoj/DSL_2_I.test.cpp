#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I"

#include "../../template/main.hpp"
#include "../../datastructure/segmenttree/lazysegmenttree.hpp"

signed main() {

    int N, Q;
    cin >> N >> Q;

    using lint = long long;
    using M = lint;
    const M ID_OM(4e18);
    auto f = [](M a, M b) -> M { return a + b; };
    auto g = [](M a, M b) -> M { return b == ID_OM ? a : b; };
    auto p = [](M a, int b) -> M { return a * b; };
    auto seg = make_segtree(N, M(0), ID_OM, f, g, g, p);

    while (Q--) {
        int q;  cin >> q;
        if (q == 0) {
            int s, t; lint x;
            cin >> s >> t >> x;
            ++t;
            seg.update(s, t, x);
        } else {
            int s, t;
            cin >> s >> t;
            ++t;
            cout << seg.query(s, t) << endl;
        }
    }

}

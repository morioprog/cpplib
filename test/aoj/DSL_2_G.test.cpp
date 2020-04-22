#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "../../template/main.hpp"
#include "../../datastructure/segmenttree/lazysegmenttree.hpp"

signed main() {

    int N, Q;
    cin >> N >> Q;

    using lint = long long;
    using M = lint;
    auto f = [](M a, M b) -> M { return a + b; };
    auto p = [](M a, int b) -> M { return a * b; };
    auto seg = make_segtree(N, M(0), M(0), f, f, f, p);

    while (Q--) {
        int q;  cin >> q;
        if (q == 0) {
            int s, t; lint x;
            cin >> s >> t >> x;
            --s;
            seg.update(s, t, x);
        } else {
            int s, t;
            cin >> s >> t;
            --s;
            cout << seg.query(s, t) << endl;
        }
    }

}

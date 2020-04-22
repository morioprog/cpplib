#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../../template/main.hpp"
#include "../../datastructure/segmenttree/lazysegmenttree.hpp"

constexpr int MODULO = 998244353;

signed main() {

    int N, Q;
    cin >> N >> Q;

    using lint = long long;
    vector<lint> A(N);
    for (auto& e: A) cin >> e;

    using M = lint;
    using OM = pair<lint, lint>;

    auto f = [](M a, M b) -> M {
        return (a + b) % MODULO;
    };
    auto g = [](M a, OM b) -> M {
        return (b.first * a + b.second) % MODULO;
    };
    auto h = [](OM a, OM b) -> OM {
        return OM((a.first * b.first) % MODULO, (a.second * b.first + b.second) % MODULO);
    };
    auto p = [](OM a, int n) -> OM {
        return OM(a.first, (a.second * n) % MODULO);
    };

    auto seg = make_segtree(A, M(0), OM(1, 0), f, g, h, p);

    while (Q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 0) {
            lint b, c;  cin >> b >> c;
            seg.update(l, r, OM(b, c));
        } else {
            cout << seg.query(l, r) << endl;
        }
    }

}

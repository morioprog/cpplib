#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E"

#include "../../template/main.hpp"
#include "../../datastructure/segmenttree/lazysegmenttree.hpp"
#include "../../graph/template.hpp"
#include "../../graph/tree/hldecomposition.hpp"

signed main() {

    int N;  cin >> N;

    HLDecomposition<int> hld(N);
    for (int i = 0; i < N; ++i) {
        int K;  cin >> K;
        while (K--) {
            int C;  cin >> C;
            hld.add_edge(i, C);
        }
    }
    hld.build();

    using lint = long long;
    using M = lint;
    auto f = [](M a, M b) -> M { return a + b; };
    auto p = [](M a, int b) -> M { return a * b; };
    auto seg = make_segtree(N, M(0), M(0), f, f, f, p);

    auto update = [&](int v, int w) -> void {
        auto prs = hld.get_path(0, v, true);
        for (auto& e: prs) seg.update(e.first, e.second, w);
    };

    auto query = [&](int u) -> lint {
        auto prs = hld.get_path(0, u, true);
        lint ret = 0;
        for (auto& e: prs) ret += seg.query(e.first, e.second);
        return ret;
    };

    int Q;  cin >> Q;
    while (Q--) {
        int T;  cin >> T;
        if (T == 0) {
            int V, W; cin >> V >> W;
            update(V, W);
        } else {
            int U;  cin >> U;
            cout << query(U) << endl;
        }
    }

}

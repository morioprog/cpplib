#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D"

#include "../../template/main.hpp"
#include "../../datastructure/segmenttree/segmenttree.hpp"
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

    SegmentTree<int> seg(N, [](int a, int b){ return a + b; }, 0);

    auto query = [&](int a) -> int {
        auto prs = hld.get_path(0, a, true);
        int ret = 0;
        for (auto& e: prs) ret += seg.query(e.first, e.second);
        return ret;
    };

    int Q;  cin >> Q;
    while (Q--) {
        int T;  cin >> T;
        if (T == 0) {
            int V, W; cin >> V >> W;
            seg.add(hld.get(V), W);
        } else {
            int U;  cin >> U;
            cout << query(U) << endl;
        }
    }

}

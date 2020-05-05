#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../../template/main.hpp"
#include "../../datastructure/segmenttree/segmenttree.hpp"
#include "../../graph/template.hpp"
#include "../../graph/tree/hldecomposition.hpp"

signed main() {

    int N, Q;
    cin >> N >> Q;

    using lint = long long;
    vector<lint> A(N);
    for (auto& e: A) cin >> e;

    HLDecomposition<lint> hld(N);
    hld.input_edges(N - 1, 0, false);
    hld.build();

    vector<lint> B(N);
    for (int i = 0; i < N; ++i) B[hld.get(i)] = A[i];
    SegmentTree<lint> seg(B, [](lint a, lint b){ return a + b; }, 0LL);

    auto query = [&](int u, int v) -> lint {
        lint ret = 0;
        auto prs = hld.query_path(u, v);
        for (auto& e: prs) {
            ret += seg.query(e.first, e.second);
        }
        return ret;
    };

    auto update = [&](int u, lint n) -> void {
        int idx = hld.get(u);
        seg.add(idx, n);
    };

    while (Q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 0) update(a, b);
        else        cout << query(a, b) << endl;
    }

}

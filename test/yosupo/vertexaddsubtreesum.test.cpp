#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "../../template/main.hpp"
#include "../../datastructure/segmenttree/segmenttree.hpp"
#include "../../graph/template.hpp"
#include "../../graph/tree/hldecomposition.hpp"

signed main() {

    int N, Q;
    cin >> N >> Q;

    using lint = long long;
    vector<lint> A(N);
    for (auto& e : A) cin >> e;

    HLDecomposition<lint> hld(N);
    for (int i = 1; i < N; ++i) {
        int P;
        cin >> P;
        hld.add_edge(P, i);
    }
    hld.build();

    vector<lint> B(N);
    for (int i = 0; i < N; ++i) B[hld.get(i)] = A[i];
    auto seg = make_segment_tree(B, 0LL, [](lint a, lint b) { return a + b; });

    auto query = [&](int u) -> lint {
        auto prs = hld.get_subtree(u);
        return seg.query(prs.first, prs.second);
    };

    auto update = [&](int u, lint n) -> void {
        int idx = hld.get(u);
        seg.update(idx, seg[idx] + n);
    };

    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int U, X;
            cin >> U >> X;
            update(U, X);
        } else {
            int U;
            cin >> U;
            cout << query(U) << endl;
        }
    }
}

#define IGNORE

#define PROBLEM "https://yukicoder.me/problems/no/399"

#include "../../template/main.hpp"
#include "../../datastructure/segmenttree/lazysegmenttree.hpp"
#include "../../graph/template.hpp"
#include "../../graph/tree/hldecomposition.hpp"

signed main() {

    int N;  cin >> N;

    HLDecomposition<int> hld(N);
    hld.input_edges(N - 1, 1, false);
    hld.build();

    using lint = long long;
    using M = lint;
    auto f = [](M a, M b) -> M { return a + b; };
    auto p = [](M a, int b) -> M { return a * b; };
    auto seg = make_segtree(N, M(0), M(0), f, f, f, p);

    auto query = [&](int u, int v) -> lint {
        auto prs = hld.get_path(u, v);
        lint ret = 0;
        for (auto& e: prs) ret += seg.query(e.first, e.second);
        return ret;
    };

    auto update = [&](int u, int v, lint num) -> void {
        auto prs = hld.get_path(u, v);
        for (auto& e: prs) seg.update(e.first, e.second, 1);
    };

    int Q;  cin >> Q;
    while (Q--) {
        int A, B;
        cin >> A >> B;
        --A, --B;
        update(A, B, 1);
    }

    lint res = 0;
    for (int i = 0; i < N; ++i) {
        lint tmp = seg.query(i, i + 1);
        res += tmp * (tmp + 1) >> 1;
    }
    cout << res << endl;

}

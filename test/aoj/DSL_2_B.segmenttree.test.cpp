#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "../../template/main.hpp"
#include "../../datastructure/segmenttree/segmenttree.hpp"

signed main() {

    int N, Q;
    cin >> N >> Q;

    auto seg = make_segment_tree(N, 0, [](int a, int b) { return a + b; });

    while (Q--) {
        int q, a, b;
        cin >> q >> a >> b;
        --a;
        if (q == 0) {
            seg.update(a, seg[a] + b);
        } else {
            cout << seg.query(a, b) << endl;
        }
    }
}

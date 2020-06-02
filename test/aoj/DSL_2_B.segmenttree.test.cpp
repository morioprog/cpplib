#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "../../template/main.hpp"
#include "../../datastructure/segmenttree/segmenttree.hpp"

signed main() {

    int N, Q;
    cin >> N >> Q;

    SegmentTree<int> seg(N, [](int a, int b){ return a + b; }, 0);

    while (Q--) {
        int q, a, b;
        cin >> q >> a >> b;
        --a;
        if (q == 0) {
            seg.add(a, b);
        } else {
            cout << seg.query(a, b) << endl;
        }
    }

}

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "../../template/main.hpp"
#include "../../datastructure/segmenttree/segmenttree.hpp"

signed main() {

    int N, Q;
    cin >> N >> Q;

    SegmentTree<int> seg(N, [](int a, int b){ return min(a, b); }, INT_MAX);

    while (Q--) {
        int q, a, b;  cin >> q >> a >> b;
        if (q == 0) {
            seg.update(a, b);
        } else {
            cout << seg.query(a, b + 1) << endl;
        }
    }

}

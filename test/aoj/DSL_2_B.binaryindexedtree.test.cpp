#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "../../template/main.hpp"
#include "../../datastructure/binaryindexedtree.hpp"

signed main() {

    int N, Q;
    cin >> N >> Q;

    BinaryIndexedTree<int> bit(N);

    while (Q--) {
        int q, a, b;
        cin >> q >> a >> b;
        --a;
        if (q == 0) {
            bit.add(a, b);
        } else {
            cout << bit.sum(a, b) << endl;
        }
    }

}

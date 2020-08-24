#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B"

#include "../../template/main.hpp"
#include "../../datastructure/unionfind/weightedunionfind.hpp"

signed main() {

    int N, M;
    cin >> N >> M;

    WeightedUnionFind<int> uf(N);
    for (int i = 0; i < M; ++i) {
        int t, a, b, w;
        cin >> t;
        if (t == 0) {
            cin >> a >> b >> w;
            uf.unite(a, b, w);
        } else {
            cin >> a >> b;
            if (not uf.same(a, b)) {
                cout << "?" << endl;
            } else {
                cout << uf.diff(a, b) << endl;
            }
        }
    }

}

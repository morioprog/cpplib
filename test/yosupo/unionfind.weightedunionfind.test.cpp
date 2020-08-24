#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../template/main.hpp"
#include "../../datastructure/unionfind/weightedunionfind.hpp"

signed main() {

    int N, Q;
    cin >> N >> Q;

    WeightedUnionFind<int> uf(N);
    while (Q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            uf.unite(u, v, 0);
        } else {
            cout << uf.same(u, v) << endl;
        }
    }

}

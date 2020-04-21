#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../template/short.hpp"
#include "../../datastructure/unionfind/unionfind.hpp"

signed main() {

    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);
    while (Q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            uf.unite(u, v);
        } else {
            cout << uf.same(u, v) << endl;
        }
    }

}

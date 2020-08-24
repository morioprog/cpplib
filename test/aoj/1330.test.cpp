#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330"

#include "../../template/main.hpp"
#include "../../datastructure/unionfind/weightedunionfind.hpp"

signed main() {

    int N, M;
    while (cin >> N >> M, N) {
        WeightedUnionFind<int> uf(N);
        for (int i = 0; i < M; ++i) {
            char c;
            int a, b, w;
            cin >> c;
            if (c == '!') {
                cin >> a >> b >> w;
                --a, --b;
                uf.unite(a, b, w);
            } else {
                cin >> a >> b;
                --a, --b;
                if (not uf.same(a, b)) {
                    cout << "UNKNOWN" << endl;
                } else {
                    cout << uf.diff(a, b) << endl;
                }
            }
        }
    }

}

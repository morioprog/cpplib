#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

#include "../../template/main.hpp"
#include "../../graph/template.hpp"
#include "../../graph/tree/hldecomposition.hpp"

signed main() {

    int N;
    cin >> N;

    HLDecomposition<int> hld(N);
    for (int i = 0; i < N; ++i) {
        int K;  cin >> K;
        for (int j = 0; j < K; ++j) {
            int C; cin >> C;
            hld.add_edge(i, C);
        }
    }
    hld.build();

    int Q;
    cin >> Q;

    while (Q--) {
        int U, V;
        cin >> U >> V;
        cout << hld.lca(U, V) << endl;
    }

}

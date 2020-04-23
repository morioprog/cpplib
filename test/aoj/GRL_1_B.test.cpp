#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#include "../../template/main.hpp"
#include "../../graph/graph.hpp"

signed main() {

    int N, M, frm;
    cin >> N >> M >> frm;

    using lint = long long;
    Graph<lint> g(N);
    g.input_arcs(M, 0, true);

    auto bf = g.bellmanford(frm);
    if (bf.size() == 0) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for (auto& e: bf) {
        if (e == g.INF) cout << "INF" << endl;
        else            cout << e << endl;
    }

}
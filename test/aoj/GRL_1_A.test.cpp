#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "../../template/main.hpp"
#include "../../graph/template.hpp"
#include "../../graph/shortestpath/dijkstra.hpp"

signed main() {

    int N, M, frm;
    cin >> N >> M >> frm;

    using lint = long long;
    Graph<lint> g(N);
    g.input_arcs(M, 0, true);

    auto dij = dijkstra(g, frm);
    for (auto& e: dij) {
        if (e == g.INF) cout << "INF" << endl;
        else            cout << e << endl;
    }

}

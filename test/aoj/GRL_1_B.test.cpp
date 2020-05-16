#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#include "../../template/main.hpp"
#include "../../graph/template.hpp"
#include "../../graph/shortestpath/bellmanford.hpp"

signed main() {

    int N, M, frm;
    cin >> N >> M >> frm;

    using lint = long long;
    Graph<lint> g(N);
    g.input_arcs(M, 0, true);

    auto bf = bellmanford(g, frm);
    if (bf.size() == 0) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    for (auto& e: bf) {
        if (e == GINF<lint>)  cout << "INF" << endl;
        else            cout << e << endl;
    }

}

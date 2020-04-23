#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include "../../template/main.hpp"
#include "../../graph/graph.hpp"

signed main() {

    int N, M;
    cin >> N >> M;

    using lint = long long;
    Graph<lint> g(N);
    g.input_arcs(M, 0, true);

    if (g.warshallfloyd()) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    for (auto& e: g.wf) {
        for (int i = 0; i < N; ++i) {
            if (e[i] == g.INF) cout << "INF";
            else               cout << e[i];
            if (i != N - 1) cout << ' ';
        }
        cout << endl;
    }

}

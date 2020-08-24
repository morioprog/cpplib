#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"

#include "../../template/main.hpp"
#include "../../graph/maximumflow/dinic.hpp"

signed main() {

    int V, E;
    cin >> V >> E;

    Dinic<int> dnc(V);
    for (int i = 0; i < E; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        dnc.add_arc(u, v, c);
    }

    cout << dnc.max_flow(0, V - 1) << endl;

}

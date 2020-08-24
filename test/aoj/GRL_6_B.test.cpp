#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B"

#include "../../template/main.hpp"
#include "../../graph/minimumcostflow/primaldual.hpp"

signed main() {

    int V, E, F;
    cin >> V >> E >> F;

    PrimalDual<int, int> pd(V);
    for (int i = 0; i < E; ++i) {
        int u, v, cap, cst;
        cin >> u >> v >> cap >> cst;
        pd.add_arc(u, v, cst, cap);
    }

    cout << pd.min_cost_flow(0, V - 1, F) << endl;

}

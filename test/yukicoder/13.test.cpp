#define PROBLEM "https://yukicoder.me/problems/no/13"

#include "../../template/main.hpp"
#include "../../graph/template.hpp"
#include "../../graph/gridgraph.hpp"
#include "../../graph/other/cycle_detection.hpp"

signed main() {

    int W, H;
    cin >> W >> H;

    vector<vector<int>> A(H, vector<int>(W, 0));
    for (auto &v : A)
        for (auto &e : v) cin >> e;

    GridGraph<int> g(H, W);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (not g.inside(ni, nj)) continue;
                if (A[i][j] != A[ni][nj]) continue;
                g.add_arc(i, j, ni, nj);
            }
        }
    }

    auto cyc = cycle_detection(g, false);
    if (cyc.empty()) {
        cout << "impossible" << endl;
    } else {
        cout << "possible" << endl;
    }
}

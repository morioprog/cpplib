#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2945"

#include "../../template/main.hpp"
#include "../../graph/template.hpp"
#include "../../graph/gridgraph.hpp"
#include "../../graph/shortestpath/01_bfs.hpp"

bool solve();

signed main() {

    while (solve()) ;

}

const int MX = 100;

bool solve() {

    int N;
    cin >> N;
    if (N == 0) return false;

    int A, B, C, D, cx, cy;
    cin >> A >> B >> C >> D >> cx >> cy;
    --A, --B, --cx, --cy;

    GridGraph<int> g(MX, MX);
    for (int h = 0; h < MX; ++h) {
        for (int w = 0; w < MX; ++w) {
            for (int i = 0; i < 4; ++i) {
                int nh = h + dx[i];
                int nw = w + dy[i];
                if (not g.inside(nh, nw)) continue;
                int cst = A <= nh and nh < C and B <= nw and nw < D;
                g.add_arc(h, w, nh, nw, !cst);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < N; ++i) {
        int X, Y;
        cin >> X >> Y;
        --X, --Y;
        auto dist = bfs_01(g, g.hash(cx, cy));
        res += dist[g.hash(X, Y)];
        cx = X, cy = Y;
    }
    cout << res << endl;

    return true;

}

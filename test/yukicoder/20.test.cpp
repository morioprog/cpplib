#define PROBLEM "https://yukicoder.me/problems/no/20"

#include "../../template/main.hpp"
#include "../../graph/template.hpp"
#include "../../graph/gridgraph.hpp"
#include "../../graph/shortestpath/dijkstra.hpp"

signed main() {

    int N, V, Ox, Oy;
    cin >> N >> V >> Ox >> Oy;
    
    GridGraph g(N, N);
    int S = g.hash(1, 1, 1);
    int G = g.hash(N, N, 1);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int L;  cin >> L;
            for (int k = 0; k < 4; ++k) {
                int fi = i + dx[k];
                int fj = j + dy[k];
                if (not g.inside(fi, fj)) continue;
                g.add_arc(fi, fj, i, j, L);
            }
        }
    }

    auto dij_S = dijkstra(g, S);
    if (dij_S[G] < V) {
        cout << "YES" << endl;
        return 0;
    }

    if (Ox == 0 and Oy == 0) {
        cout << "NO" << endl;
        return 0;
    }

    swap(Ox, Oy);
    int O = g.hash(Ox, Oy, 1);
    auto dij_O = dijkstra(g, O);
    V -= dij_S[O];

    if (V <= 0) {
        cout << "NO" << endl;
        return 0;
    }

    V *= 2;
    V -= dij_O[G];
    
    if (V > 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}

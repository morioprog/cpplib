#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/7/GRL_7_A"

#include "../../template/main.hpp"
#include "../../graph/template.hpp"
#include "../../graph/bipartite/bipartite_matching.hpp"

signed main() {

    int X, Y, E;
    cin >> X >> Y >> E;

    Graph<int> g(X + Y);
    for (int i = 0; i < E; ++i) {
        int x, y;
        cin >> x >> y;
        g.add_edge(x, y + X);
    }

    cout << bipartite_matching(g) << endl;

}

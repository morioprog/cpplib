#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B"

#include "../../template/main.hpp"
#include "../../graph/template.hpp"
#include "../../graph/other/topological_sort.hpp"

signed main() {

    int V, E;
    cin >> V >> E;

    Graph<int> g(V);
    g.input_arcs(E);

    auto tp = topological_sort(g);
    for (auto& e: tp) cout << e << endl;

}

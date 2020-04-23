#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A"

#include "../../template/main.hpp"
#include "../../graph/template.hpp"
#include "../../datastructure/unionfind/unionfind.hpp"
#include "../../graph/minimumspanningtree/kruskal.hpp"

signed main() {

    int N, M;
    cin >> N >> M;

    Graph<int> g(N);
    g.input_edges(M, 0, true);

    cout << g.kruskal() << endl;

}

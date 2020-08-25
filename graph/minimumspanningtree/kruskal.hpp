/**
* @brief クラスカル法
* @docs docs/graph/minimumspanningtree/kruskal.md
*/

template <typename T>
T kruskal(const Graph<T> &g) {
    vector<Edge<T>> edges;
    for (int i = 0; i < g.V; ++i)
        for (auto &e : g.mat[i]) edges.emplace_back(e);
    sort(edges.begin(), edges.end(), [](const Edge<T> &a, const Edge<T> &b) {
        return a.cst < b.cst;
    });
    UnionFind uf(g.V);
    T ret(0);
    for (auto &e : edges)
        if (uf.unite(e.frm, e.to)) ret += e.cst;
    return ret;
}

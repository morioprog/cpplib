/**
* @brief クラスカル法
* @docs docs/graph/minimumspanningtree/kruskal.md
*/

template<typename T>
T Graph<T>::kruskal() {
    vector<Edge> edges;
    for (int i = 0; i < V; ++i) for (auto& e: mat[i]) edges.emplace_back(e);
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.cst < b.cst;
    });
    UnionFind uf(V);
    T ret(0);
    for (auto& e : edges) if (uf.unite(e.frm, e.to)) ret += e.cst;
    return ret;
}

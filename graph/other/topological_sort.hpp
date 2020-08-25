/**
* @brief トポロジカルソート
* @docs docs/graph/other/topological_sort.md
*/

template <typename T>
vector<int> topological_sort(const Graph<T> &g) {
    vector<int> order, color(g.V, 0);
    auto rec = [&](auto &&f, int v) -> bool {
        color[v] = 1;
        for (auto &e : g.mat[v]) {
            if (color[e] == 2) continue;
            if (color[e] == 1) return false;
            if (not f(f, e)) return false;
        }
        order.push_back(v);
        color[v] = 2;
        return true;
    };
    for (int i = 0; i < g.V; ++i)
        if (not color[i] and not rec(rec, i)) return vector<int>();
    reverse(order.begin(), order.end());
    return order;
}

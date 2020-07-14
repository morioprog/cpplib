/**
 * @brief Bipartite Check
 * @docs docs/graph/bipartite/bipartite_check.md
 */

template<typename T>
// int is_bipartite(const Graph<T> &g) {
bool is_bipartite(const Graph<T> &g) {
    bool isbi = true;
    vector<int> color(g.V, 0);
    auto dfs = [&](auto &&f, int i, int clr) -> void {
        if (color[i] != 0) return;
        color[i] = clr;
        for (auto& e: g.mat[i]) {
            /* */if (color[e.to] == 0)      f(f, e.to, -clr);
            else if (color[e.to] == clr)    isbi = false;
        }
    };
    dfs(dfs, 0, 1);
    return isbi;
    // int cnt = 0;
    // for (auto& e: color) if (e == 1) ++cnt;
    // return isbi ? -1 : cnt;
}

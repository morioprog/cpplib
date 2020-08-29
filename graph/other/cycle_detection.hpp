/**
* @brief 閉路検出
* @docs docs/graph/other/cycle_detection.md
*/

template <typename T>
vector<int> cycle_detection(const Graph<T> &g, bool directed = false) {
    vector<int> cycle, color(g.V, 0);
    auto dfs = [&](auto &&f, int cur, int prv, int &frm) -> bool {
        color[cur] = 1;
        for (auto &nxt : g.mat[cur]) {
            if (not directed and nxt == prv) continue;
            if (color[nxt] == 0) {
                if (f(f, nxt, cur, frm)) {
                    cycle.emplace_back(cur);
                    return frm != cur;
                } else if (not cycle.empty())
                    return false;
            } else if (color[nxt] == 1) {
                cycle.emplace_back(cur);
                frm = nxt;
                return true;
            }
        }
        color[cur] = 2;
        return false;
    };
    int frm = -1;
    for (int i = 0; i < g.V; ++i) {
        if (color[i] == 0) {
            dfs(dfs, i, -1, frm);
            if (not cycle.empty()) {
                reverse(cycle.begin(), cycle.end());
                break;
            }
        }
    }
    return cycle;
}

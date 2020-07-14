/**
 * @brief Bipartite Matching
 * @docs docs/graph/bipartite/bipartite_matching.md
 * @see https://qiita.com/drken/items/e805e3f514acceb87602
 * @see https://qiita.com/drken/items/7f98315b56c95a6181a4
 */

template<typename T>
int bipartite_matching(const Graph<T> &g) {
    int timestamp = 0;
    vector<int> alive(g.V, 1), used(g.V, 0), match(g.V, -1);
    auto dfs = [&](auto &&f, int cur) -> bool {
        used[cur] = timestamp;
        for (auto& nxt: g.mat[cur]) {
            int w = match[nxt];
            if (alive[nxt] == 0) continue;
            if (w == -1 or (used[w] != timestamp and f(f, w))) {
                match[cur] = nxt;
                match[nxt] = cur;
                return true;
            }
        }
        return false;
    };
    int ret = 0;
    for (int i = 0; i < g.V; ++i) {
        if (alive[i] == 0) continue;
        if (match[i] == -1) {
            ++timestamp;
            ret += dfs(dfs, i);
        }
    }
    return ret;
}

/**
* @brief ベルマンフォード法
* @docs docs/graph/shortestpath/bellmanford.md
*/

template<typename T>
vector<T> bellmanford(const Graph<T> &g, int frm) {
    vector<T> ret(g.V, GINF<T>);    ret[frm] = 0;
    for (int i = 0; i < g.V - 1; ++i) {
        for (int j = 0; j < g.V; ++j) {
            for (auto& e: g.mat[j]) {
                if (ret[e.frm] == GINF<T>) continue;
                ret[e.to] = min(ret[e.to], ret[e.frm] + e.cst);
            }
        }
    }
    for (int j = 0; j < g.V; ++j) {
        for (auto& e: g.mat[j]) {
            if (ret[e.frm] == GINF<T>) continue;
            if (ret[e.frm] + e.cst < ret[e.to]) return vector<T>();
        }
    }
    return ret;
}

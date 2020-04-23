/**
* @brief ベルマンフォード法
* @docs docs/graph/shortestpath/bellmanford.md
*/

template<typename T>
vector<T> Graph<T>::bellmanford(int frm) {
    vector<T> ret(V, INF);  ret[frm] = 0;
    for (int i = 0; i < V - 1; ++i) {
        for (int j = 0; j < V; ++j) {
            for (auto& e: mat[j]) {
                if (ret[e.frm] == INF) continue;
                ret[e.to] = min(ret[e.to], ret[e.frm] + e.cst);
            }
        }
    }
    for (int j = 0; j < V; ++j) {
        for (auto& e: mat[j]) {
            if (ret[e.frm] == INF) continue;
            if (ret[e.frm] + e.cst < ret[e.to]) return vector<T>();
        }
    }
    return ret;
}

/**
* @brief ダイクストラ法
* @docs docs/graph/shortestpath/dijkstra.md
*/

template<typename T>
vector<T> dijkstra(Graph<T> &g, int frm) {
    using P = pair<T, int>;
    vector<T> ret(g.V, g.INF);  ret[frm] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(ret[frm], frm);
    while (not pq.empty()) {
        T cst;  int idx;
        tie(cst, idx) = pq.top();   pq.pop();
        if (ret[idx] < cst) continue;
        for (auto& e: g.mat[idx]) {
            T nxt_cst = cst + e.cst;
            if (ret[e.to] <= nxt_cst) continue;
            ret[e.to] = nxt_cst;
            pq.emplace(ret[e.to], e.to);
        }
    }
    return ret;
}

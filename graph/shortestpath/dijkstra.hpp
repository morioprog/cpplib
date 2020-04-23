/**
* @brief ダイクストラ法
* @docs docs/graph/shortestpath/dijkstra.md
*/

template<typename T>
vector<T> Graph<T>::dijkstra(int frm) {
    vector<T> ret(V, INF);  ret[frm] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(ret[frm], frm);
    while (not pq.empty()) {
        T cst;  int idx;
        tie(cst, idx) = pq.top();   pq.pop();
        if (ret[idx] < cst) continue;
        for (auto& e: mat[idx]) {
            T nxt_cst = cst + e.cst;
            if (ret[e.to] <= nxt_cst) continue;
            ret[e.to] = nxt_cst;
            pq.emplace(ret[e.to], e.to);
        }
    }
    return ret;
}

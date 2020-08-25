/**
* @brief 01-BFS
* @docs docs/graph/shortestpath/01_bfs.md
*/

template <typename T>
vector<T> bfs_01(const Graph<T>& g, int frm) {
    vector<T> ret(g.V, GINF<T>);
    ret[frm] = 0;
    deque<int> dq;
    dq.emplace_back(frm);
    while (not dq.empty()) {
        int idx = dq.front();
        dq.pop_front();
        for (auto& e : g.mat[idx]) {
            T nxt_cst = ret[idx] + e.cst;
            if (ret[e.to] <= nxt_cst) continue;
            ret[e.to] = nxt_cst;
            if (e.cst == 0) dq.emplace_front(e.to);
            else
                dq.emplace_back(e.to);
        }
    }
    return ret;
}

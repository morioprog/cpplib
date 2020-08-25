/**
* @brief Primal Dual
* @docs docs/graph/minimumcostflow/primaldual.md
* @see http://www.prefield.com/algorithm/graph/primal_dual.html
* @note O(FE\log V)
*/

template <typename Cst, typename Cap>
struct PrimalDual {
    struct CapEdge {
        int to, rev;
        Cst cst;
        Cap cap;
        CapEdge() {}
        CapEdge(int t, int r, Cst cst, Cap cap)
            : to(t), rev(r), cst(cst), cap(cap) {}
        operator int() const { return to; }
    };
    using P = pair<Cst, int>;
    const Cst INF;
    int V;
    vector<vector<CapEdge>> graph;
    vector<Cst> pot, min_cst;
    vector<int> prv_v, prv_e;
    PrimalDual(int V)
        : INF(numeric_limits<Cst>::max()), V(V), graph(V) {}
    void add_arc(int a, int b, Cst cst, Cap cap) {
        graph[a].emplace_back(b, (int)graph[b].size(), cst, cap);
        graph[b].emplace_back(a, (int)graph[a].size() - 1, -cst, 0);
    }
    Cst min_cost_flow(int s, int t, Cap flw) {
        pot.assign(V, 0);
        prv_e.assign(V, -1);
        prv_v.assign(V, -1);
        Cst ret = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        while (flw > 0) {
            min_cst.assign(V, INF);
            pq.push(P(0, s));
            min_cst[s] = 0;
            while (not pq.empty()) {
                Cst cst;
                int idx;
                tie(cst, idx) = pq.top();
                pq.pop();
                if (min_cst[idx] < cst) continue;
                for (int i = 0; i < (int)graph[idx].size(); ++i) {
                    CapEdge &nxt = graph[idx][i];
                    int nxt_cst  = min_cst[idx] + nxt.cst + pot[idx] - pot[nxt];
                    if (nxt.cap > 0 and min_cst[nxt] > nxt_cst) {
                        min_cst[nxt] = nxt_cst;
                        prv_v[nxt] = idx, prv_e[nxt] = i;
                        pq.push(P(min_cst[nxt], nxt));
                    }
                }
            }
            if (min_cst[t] == INF) return -1;
            for (int v = 0; v < V; ++v) pot[v] += min_cst[v];
            Cap add_flw = flw;
            for (int v = t; v != s; v = prv_v[v]) {
                add_flw = min(add_flw, graph[prv_v[v]][prv_e[v]].cap);
            }
            flw -= add_flw;
            ret += add_flw * pot[t];
            for (int v = t; v != s; v = prv_v[v]) {
                CapEdge &e = graph[prv_v[v]][prv_e[v]];
                e.cap -= add_flw;
                graph[v][e.rev].cap += add_flw;
            }
        }
        return ret;
    }
};

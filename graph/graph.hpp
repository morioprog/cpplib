/**
* @brief グラフテンプレート
* @docs docs/graph/graph.md
*/

template<typename T>
struct Graph {
    using P = pair<T, int>;
    using Matrix = vector<vector<T>>;
    struct Edge {
        int frm, to;    T cst;
        Edge() {}
        Edge(int f, int t, T c) : frm(f), to(t), cst(c) {}
    };
    int V, E;   const T INF;
    vector<vector<Edge>> mat;
    Matrix wf;
    Graph() {}
    Graph(int v) : V(v), E(0),INF(numeric_limits<T>::max() / 10), mat(v) {}
    inline void add_edge(int a, int b, T c, int margin = 0) {
        a -= margin, b -= margin, E += 2;
        mat[a].emplace_back(a, b, c);
        mat[b].emplace_back(b, a, c);
        if ((int)wf.size() == 0) return;
        warshallfloyd_update(a, b, c);
        warshallfloyd_update(b, a, c);
    }
    inline void add_arc(int a, int b, T c, int margin = 0) {
        a -= margin, b -= margin, E += 1;
        mat[a].emplace_back(a, b, c);
        if ((int)wf.size() == 0) return;
        warshallfloyd_update(a, b, c);
    }
    inline void input_edges(int M, int margin = 0, bool need_cost = false) {
        for (int i = 0; i < M; ++i) {
            if (need_cost) {
                int a, b;   T c;
                cin >> a >> b >> c;
                add_edge(a, b, c, margin);
            } else {
                int a, b;   T c(1);
                cin >> a >> b;
                add_edge(a, b, c, margin);
            }
        }
    }
    inline void input_arcs(int M, int margin = 0, bool need_cost = false) {
        for (int i = 0; i < M; ++i) {
            if (need_cost) {
                int a, b;   T c;
                cin >> a >> b >> c;
                add_arc(a, b, c, margin);
            } else {
                int a, b;   T c(1);
                cin >> a >> b;
                add_arc(a, b, c, margin);
            }
        }
    }
    inline vector<T> dijkstra(int frm) {
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
    inline vector<T> bellmanford(int frm) {
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
    inline bool warshallfloyd() {
        wf.assign(V, vector<T>(V, INF));
        for (int i = 0; i < V; ++i) wf[i][i] = 0;
        for (int i = 0; i < V; ++i) {
            for (auto& e: mat[i]) {
                wf[e.frm][e.to] = min(wf[e.frm][e.to], e.cst);
            }
        }
        for (int k = 0; k < V; ++k) {
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < V; ++j) {
                    if (wf[i][k] != INF and wf[k][j] != INF) {
                        wf[i][j] = min(wf[i][j], wf[i][k] + wf[k][j]);
                    }
                }
            }
        }
        bool hasnegcycle = false;
        for (int i = 0; i < V; ++i) hasnegcycle |= wf[i][i] < 0;
        return hasnegcycle;
    }
    inline void warshallfloyd_update(int frm, int to, T cst = 1) {
        if (wf[frm][to] <= cst) return;
        wf[frm][to] = cst;
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (wf[i][frm] != INF and wf[frm][j] != INF) {
                    wf[i][j] = min(wf[i][j], wf[i][frm] + wf[frm][j]);
                }
            }
        }
    }
};

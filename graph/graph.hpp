/**
* @brief グラフテンプレート
* @docs docs/graph/graph.md
*/

template<typename T>
struct Graph {
    struct Edge {
        int frm, to;    T cst;
        Edge() {}
        Edge(int f, int t, T c) : frm(f), to(t), cst(c) {}
    };
    int V, E;   const T INF;
    using P = pair<T, int>;
    vector<Edge> edges;
    vector<vector<Edge>> mat;
    Graph() {}
    Graph(int v) : V(v), E(0), INF(numeric_limits<T>::max() / 10), edges(0), mat(v) {}
    inline void add_edge(int a, int b, T c, int margin = 0) {
        a -= margin, b -= margin, E += 2;
        edges.emplace_back(a, b, c);
        edges.emplace_back(b, a, c);
        mat[a].emplace_back(a, b, c);
        mat[b].emplace_back(b, a, c);
    }
    inline void add_arc(int a, int b, T c, int margin = 0) {
        a -= margin, b -= margin, E += 1;
        edges.emplace_back(a, b, c);
        mat[a].emplace_back(a, b, c);
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
        E += M;
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
};

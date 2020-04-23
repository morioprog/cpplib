/**
* @brief グラフテンプレート
* @docs docs/graph/template.md
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
    }
    inline void add_arc(int a, int b, T c, int margin = 0) {
        a -= margin, b -= margin, E += 1;
        mat[a].emplace_back(a, b, c);
        if ((int)wf.size() == 0) return;
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
    vector<T> dijkstra(int frm);
    vector<T> bellmanford(int frm);
    bool warshallfloyd();
    void warshallfloyd_update(int frm, int to, T cst);
    void warshallfloyd_add_arc(int frm, int to, T cst);
    void warshallfloyd_add_edge(int frm, int to, T cst);
};

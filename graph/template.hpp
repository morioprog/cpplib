/**
* @brief グラフテンプレート
* @docs docs/graph/template.md
*/

template<typename T>
struct Edge {
    int frm, to;    T cst;
    Edge() {}
    Edge(int f, int t, T c) : frm(f), to(t), cst(c) {}
};

template<typename T>
struct Graph {
    int V, E;   const T INF;
    vector<vector<Edge<T>>> mat;
    vector<vector<T>> wf;
    Graph() {}
    Graph(int v) : V(v), E(0), INF(numeric_limits<T>::max() / 10), mat(v) {}
    inline void add_edge(int a, int b, T c, int margin = 0) {
        a -= margin, b -= margin, E += 2;
        mat[a].emplace_back(a, b, c);
        mat[b].emplace_back(b, a, c);
    }
    inline void add_arc(int a, int b, T c, int margin = 0) {
        a -= margin, b -= margin, E += 1;
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
};

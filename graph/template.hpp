/**
* @brief グラフテンプレート
* @docs docs/graph/template.md
*/

template<typename T>
struct Edge {
    int frm, to, idx;   T cst;
    Edge() {}
    Edge(int f, int t, T c, int i = -1) : frm(f), to(t), cst(c), idx(i) {}
    operator int() const { return to; }
};

template<typename T>
constexpr T GINF = numeric_limits<T>::max() / 10;

template<typename T>
struct Graph {
    int V, E;
    vector<vector<Edge<T>>> mat;
    vector<vector<T>> wf;
    Graph() {}
    Graph(int v) : V(v), E(0), mat(v) {}
    inline void add_edge(int a, int b, T c = 1, int margin = 0) {
        a -= margin, b -= margin;
        mat[a].emplace_back(a, b, c, E++);
        mat[b].emplace_back(b, a, c, E++);
    }
    inline void add_arc(int a, int b, T c = 1, int margin = 0) {
        a -= margin, b -= margin;
        mat[a].emplace_back(a, b, c, E++);
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
    inline int isbipartite() {
        bool isbi = true;
        vector<int> color(V, 0);
        function<void(int, int)> dfs = [&](int i, int clr) {
            if (color[i] != 0) return;
            color[i] = clr;
            for (auto& e: mat[i]) {
                if (color[e.to] == 0) dfs(e.to, -clr);
                else if (color[e.to] == clr) isbi = false;
            }
        };
        dfs(0, 1);
        int cnt = 0;
        for (auto& e: color) if (e == 1) ++cnt;
        return isbi ? -1 : cnt;
    }
};

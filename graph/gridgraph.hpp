/**
* @brief グリッドグラフ
* @docs docs/graph/gridgraph.md
*/

template<typename T=int>
struct GridGraph : Graph<T> {
    using Graph<T>::V;
    using Graph<T>::E;
    using Graph<T>::mat;
    const int Gdx[9] = { 1, 0, -1,  0,  1, -1, -1, 1, 0 };
    const int Gdy[9] = { 0, 1,  0, -1, -1, -1,  1, 1, 0 };
    int H, W;
    GridGraph() {}
    GridGraph(int h, int w) : H(h), W(w) {
        V = h * w;
        E = 0;
        mat.resize(V);
    }
    inline bool inside(const int h, const int w) const {
        return h >= 0 and w >= 0 and h < H and w < W;
    }
    inline int hash(const int h, const int w, const int margin = 0) const {
        return (h - margin) * W + (w - margin);
    }
    inline void add_edge(int ax, int ay, int bx, int by, T c = 1, int margin = 0) {
        ax -= margin, ay -= margin, bx -= margin, by -= margin;
        int a = hash(ax, ay), b = hash(bx, by);
        mat[a].emplace_back(a, b, c, E++);
        mat[b].emplace_back(b, a, c, E++);
    }
    inline void add_edge(pair<int, int> ap, pair<int, int> bp, T c = 1, int margin = 0) {
        int ax, ay, bx, by;
        tie(ax, ay) = ap;
        tie(bx, by) = bp;
        ax -= margin, ay -= margin, bx -= margin, by -= margin;
        int a = hash(ax, ay), b = hash(bx, by);
        mat[a].emplace_back(a, b, c, E++);
        mat[b].emplace_back(b, a, c, E++);
    }
    inline void add_arc(int ax, int ay, int bx, int by, T c = 1, int margin = 0) {
        ax -= margin, ay -= margin, bx -= margin, by -= margin;
        int a = hash(ax, ay), b = hash(bx, by);
        mat[a].emplace_back(a, b, c, E++);
    }
    inline void add_arc(pair<int, int> ap, pair<int, int> bp, T c = 1, int margin = 0) {
        int ax, ay, bx, by;
        tie(ax, ay) = ap;
        tie(bx, by) = bp;
        ax -= margin, ay -= margin, bx -= margin, by -= margin;
        int a = hash(ax, ay), b = hash(bx, by);
        mat[a].emplace_back(a, b, c, E++);
    }
    inline void input_edges(int M, int margin = 0, bool need_cost = false) {
        for (int i = 0; i < M; ++i) {
            if (need_cost) {
                int ax, ay, bx, by; T c;
                cin >> ax >> ay >> bx >> by >> c;
                add_edge(ax, ay, bx, by, c, margin);
            } else {
                int ax, ay, bx, by; T c(1);
                cin >> ax >> ay >> bx >> by;
                add_edge(ax, ay, bx, by, c, margin);
            }
        }
    }
    inline void input_arcs(int M, int margin = 0, bool need_cost = false) {
        for (int i = 0; i < M; ++i) {
            if (need_cost) {
                int ax, ay, bx, by; T c;
                cin >> ax >> ay >> bx >> by >> c;
                add_arc(ax, ay, bx, by, c, margin);
            } else {
                int ax, ay, bx, by; T c(1);
                cin >> ax >> ay >> bx >> by;
                add_arc(ax, ay, bx, by, c, margin);
            }
        }
    }
    template<typename B, typename C>
    inline void load_board(const B &board, const C ng, const int cost = 1, const int neighbor = 4) {
        assert(board.size() == H);
        if (H > 0) assert(board[0].size() == W);
        assert(neighbor >= 1 and neighbor <= 9);
        for (int h = 0; h < H; ++h) {
            for (int w = 0; w < W; ++w) {
                if (board[h][w] == ng) continue;
                for (int i = 0; i < neighbor; ++i) {
                    int nh = h + Gdx[i];
                    int nw = w + Gdy[i];
                    if (not inside(nh, nw)) continue;
                    if (board[nh][nw] == ng) continue;
                    add_arc(h, w, nh, nw, cost);
                }
            }
        }
    }
};

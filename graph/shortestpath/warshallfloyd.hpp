/**
* @brief ワーシャルフロイド法
* @docs docs/graph/shortestpath/warshallfloyd.md
*/

template <typename T>
bool warshallfloyd(Graph<T> &g) {
    g.wf.assign(g.V, vector<T>(g.V, GINF<T>));
    for (int i = 0; i < g.V; ++i) g.wf[i][i] = 0;
    for (int i = 0; i < g.V; ++i)
        for (auto &e : g.mat[i]) g.wf[e.frm][e.to] = min(g.wf[e.frm][e.to], e.cst);
    for (int k = 0; k < g.V; ++k)
        for (int i = 0; i < g.V; ++i)
            for (int j = 0; j < g.V; ++j) {
                if (g.wf[i][k] != GINF<T> and g.wf[k][j] != GINF<T>) g.wf[i][j] = min(g.wf[i][j], g.wf[i][k] + g.wf[k][j]);
            }
    bool hasnegcycle = false;
    for (int i = 0; i < g.V; ++i) hasnegcycle |= g.wf[i][i] < 0;
    return hasnegcycle;
}

template <typename T>
void warshallfloyd_update(Graph<T> &g, int frm, int to, T cst) {
    if (g.wf[frm][to] <= cst) return;
    g.wf[frm][to] = cst;
    for (int i = 0; i < g.V; ++i) {
        for (int j = 0; j < g.V; ++j) {
            if (g.wf[i][frm] != GINF<T> and g.wf[frm][j] != GINF<T>) {
                g.wf[i][j] = min(g.wf[i][j], g.wf[i][frm] + g.wf[frm][j]);
            }
        }
    }
}

template <typename T>
void warshallfloyd_add_arc(Graph<T> &g, int frm, int to, T cst) {
    g.add_arc(frm, to, cst);
    warshallfloyd_update(g, frm, to, cst);
}

template <typename T>
void warshallfloyd_add_edge(Graph<T> &g, int frm, int to, T cst) {
    g.add_edge(frm, to, cst);
    warshallfloyd_update(g, frm, to, cst);
    warshallfloyd_update(g, to, frm, cst);
}

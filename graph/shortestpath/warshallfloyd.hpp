/**
* @brief ワーシャルフロイド法
* @docs docs/graph/shortestpath/warshallfloyd.md
*/

template<typename T>
bool Graph<T>::warshallfloyd() {
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

template<typename T>
void Graph<T>::warshallfloyd_update(int frm, int to, T cst) {
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

template<typename T>
void Graph<T>::warshallfloyd_add_arc(int frm, int to, T cst) {
    add_arc(frm, to, cst);
    warshallfloyd_update(frm, to, cst);
}

template<typename T>
void Graph<T>::warshallfloyd_add_edge(int frm, int to, T cst) {
    add_edge(frm, to, cst);
    warshallfloyd_update(frm, to, cst);
    warshallfloyd_update(to, frm, cst);
}

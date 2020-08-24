/**
* @brief Dinic法
* @docs docs/graph/maximumflow/dinic.md
* @note O(E * V ^ 2)
*/

template <typename T>
struct Dinic {
    struct CapEdge {
        int to, rev;
        T cap;
        CapEdge() {}
        CapEdge(int t, int r, T c) : to(t), rev(r), cap(c) {}
        operator int() const { return to; }
    };
    const T INF;
    vector<vector<CapEdge>> graph;
    vector<T> min_cst;
    vector<int> itr;
    Dinic(int n) : INF(numeric_limits<T>::max()) { graph.resize(n); }
    void add_arc(int a, int b, T c) {
        graph[a].emplace_back(b, (int)graph[b].size(), c);
        graph[b].emplace_back(a, (int)graph[a].size() - 1, 0);
    }
    void add_edge(int a, int b, T c) {
        graph[a].emplace_back(b, (int)graph[b].size(), c);
        graph[b].emplace_back(a, (int)graph[a].size() - 1, c);
    }
    bool bfs(int s, int t) {
        queue<int> que;
        min_cst.assign((int)graph.size(), -1);
        min_cst[s] = 0;
        que.emplace(s);
        while (not que.empty()) {
            int idx = que.front();
            que.pop();
            for (auto& nxt : graph[idx]) {
                if (nxt.cap > 0 and min_cst[nxt] == -1) {
                    min_cst[nxt] = min_cst[idx] + 1;
                    que.emplace(nxt);
                }
            }
        }
        return min_cst[t] != -1;
    }
    T dfs(int idx, const int t, T flw) {
        if (idx == t) return flw;
        for (int& i = itr[idx]; i < (int)graph[idx].size(); ++i) {
            CapEdge& nxt = graph[idx][i];
            if (nxt.cap > 0 and min_cst[idx] < min_cst[nxt]) {
                T d = dfs(nxt, t, min(flw, nxt.cap));
                if (d > 0) {
                    nxt.cap -= d;
                    graph[nxt][nxt.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    T max_flow(int s, int t) {
        T ret = 0;
        while (bfs(s, t)) {
            itr.assign(graph.size(), 0);
            for (T tmp; (tmp = dfs(s, t, INF)) > 0; ) ret += tmp;
        }
        return ret;
    }
};

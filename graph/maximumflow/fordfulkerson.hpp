/**
* @brief FordFulkerson法
* @docs docs/graph/maximumflow/fordfulkerson.md
* @see http://yosupo.hatenablog.com/entry/2015/03/31/134336
* @note O(E * F) (F : 最大フロー)
*/

template <typename T>
struct FordFulkerson {
    struct CapEdge {
        int to, rev;
        T cap;
        CapEdge() {}
        CapEdge(int t, int r, T c)
            : to(t), rev(r), cap(c) {}
        operator int() const { return to; }
    };
    const T INF;
    int timestamp;
    vector<int> used;
    vector<vector<CapEdge>> graph;
    FordFulkerson(int n)
        : INF(numeric_limits<T>::max()), timestamp(0), used(n, -1), graph(n) {}
    void add_arc(int a, int b, T c) {
        graph[a].emplace_back(b, (int)graph[b].size(), c);
        graph[b].emplace_back(a, (int)graph[a].size() - 1, 0);
    }
    void add_edge(int a, int b, T c) {
        graph[a].emplace_back(b, (int)graph[b].size(), c);
        graph[b].emplace_back(a, (int)graph[a].size() - 1, c);
    }
    T dfs(int idx, const int t, T flw) {
        if (idx == t) return flw;
        used[idx] = timestamp;
        for (auto& nxt : graph[idx]) {
            if (nxt.cap > 0 and used[nxt] != timestamp) {
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
        for (T tmp; (tmp = dfs(s, t, INF)) > 0; ++timestamp) ret += tmp;
        return ret;
    }
};

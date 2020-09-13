/**
* @brief 燃やす埋める
* @docs docs/graph/maximumflow/moyasu_umeru.md
* @see https://yosupo.hatenablog.com/entry/2015/03/31/134336
*/

template <typename T>
struct moyasu_umeru {
    int N;
    T margin;
    const int R, B;  // R:red, B:blue
    const T INF;
    vector<tuple<int, int, T>> edges;
    moyasu_umeru(int V, T INF = numeric_limits<T>::max() / 10)
        : N(V + 2), margin(0), R(V), B(V + 1), INF(INF) {}
    void red_blue_penalty(int r, int b, T pena) {
        edges.emplace_back(r, b, pena);
    }
    void red_penalty(int r, T pena) {
        red_blue_penalty(r, B, pena);
    }
    void blue_penalty(int b, T pena) {
        red_blue_penalty(R, b, pena);
    }
    void red_reward(int r, T rwrd) {
        margin += rwrd;
        blue_penalty(r, rwrd);
    }
    void blue_reward(int b, T rwrd) {
        margin += rwrd;
        red_penalty(b, rwrd);
    }
    void reds_reward(vector<int> v_r, T rwrd) {
        margin += rwrd;
        edges.emplace_back(R, N, rwrd);
        for (auto& r : v_r) edges.emplace_back(N, r, INF);
        ++N;
    }
    void blues_reward(vector<int> v_b, T rwrd) {
        margin += rwrd;
        edges.emplace_back(N, B, rwrd);
        for (auto& b : v_b) edges.emplace_back(b, N, INF);
        ++N;
    }
};

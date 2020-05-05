/**
* @brief HL分解
* @docs docs/graph/tree/hldecomposition.md
*/

template<typename T>
struct HLDecomposition : Graph<T> {
    using Graph<T>::Graph;
    using Graph<T>::mat;
    using Graph<T>::V;
    vector<int> sub, dep, par, head, in, out, rev;
    vector<T> dst;
    void build(const int root = 0) {
        sub.assign(V, 0);
        dep.assign(V, 0);
        par.assign(V, 0);
        head.assign(V, 0);
        in.assign(V, 0);
        out.assign(V, 0);
        rev.assign(V, 0);
        dst.assign(V, T(0));
        dfs_sz(root, -1, 0, T(0));
        int t = 0;
        dfs_hld(root, -1, t);
    }
    int get(int u) const { return in[u]; }
    int lca(int u, int v) const {
        for (;; v = par[head[v]]) {
            // uよりもvを後に来るようにして, vを上に押し上げていく
            if (in[u] > in[v]) swap(u, v);
            if (head[u] == head[v]) return u;
        }
    }
    T dist(int u, int v) const {
        return dst[u] + dst[v] - 2 * dst[lca(u, v)];
    }
    pair<int, int> query_subtree(int u, bool isEdge = false) const {
        return make_pair(in[u] + isEdge, out[u]);
    }
    vector<pair<int, int>> query_path(int u, int v, bool isEdge = false) {
        vector<pair<int, int>> ret;
        for(;; v = par[head[v]]) {
			if (in[u] > in[v]) swap(u, v);
			if (head[u] == head[v]) break;
			ret.emplace_back(in[head[v]], in[v] + 1);
		}
		ret.emplace_back(in[u] + isEdge, in[v] + 1);
		return ret;
    }
    void dfs_sz(int cur, int prv, int depth, T weight) {
        sub[cur] = 1;
        dep[cur] = depth;
        par[cur] = prv;
        dst[cur] = weight;
        // 0番目をheavy-pathにするための比較対象を設定
        if (mat[cur].size() && mat[cur][0] == prv)
            swap(mat[cur][0], mat[cur].back());
        for (auto& nxt : mat[cur]) {
            if (nxt == prv) continue;
            dfs_sz(nxt, cur, depth + 1, weight + nxt.cst);
            sub[cur] += sub[nxt];
            if (sub[mat[cur][0]] < sub[nxt]) swap(mat[cur][0], nxt);
        }
    }
    void dfs_hld(int cur, int prv, int& times) {
        in[cur] = times++;
        rev[in[cur]] = cur;
        for (auto& nxt : mat[cur]) {
            if (nxt == prv) continue;
            // cur-nxtがheavy-path上ならheadは同じ
            head[nxt] = mat[cur][0] == nxt ? head[cur] : nxt;
            dfs_hld(nxt, cur, times);
        }
        out[cur] = times;
    }
};

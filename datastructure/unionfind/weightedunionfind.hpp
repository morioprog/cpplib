/**
* @brief 重み付きUnionFind
* @docs docs/datastructure/unionfind/weightedunionfind.md
* @see https://qiita.com/drken/items/cce6fc5c579051e64fab
*/

template <typename T>
struct WeightedUnionFind {
    int sz;
    vector<int> parent;
    vector<T> diff_weight;
    WeightedUnionFind(int sz)
        : sz(sz), parent(sz, -1), diff_weight(sz, T(0)) {}
    // weight(y) = weight(x) + w
    bool unite(int x, int y, T w) {
        w += weight(x) - weight(y);
        if ((x = find(x)) != (y = find(y))) {
            if (parent[y] < parent[x]) swap(x, y), w = -w;
            --sz;
            parent[x] += parent[y];
            parent[y]      = x;
            diff_weight[y] = w;
        }
        return true;
    }
    int find(int x) {
        if (parent[x] < 0) return x;
        int ret = find(parent[x]);
        diff_weight[x] += diff_weight[parent[x]];
        return parent[x] = ret;
    }
    T weight(int x) {
        find(x);
        return diff_weight[x];
    }
    T diff(int x, int y) { return weight(y) - weight(x); }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return -parent[find(x)]; }
    int size() { return sz; }
};

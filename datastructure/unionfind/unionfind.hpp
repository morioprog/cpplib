/**
* @brief UnionFind
* @docs docs/datastructure/unionfind/unionfind.md
*/

struct UnionFind {
    int sz;
    vector<int> parent;
    UnionFind(int sz) : sz(sz), parent(sz, -1) {}
    bool unite(int x, int y) {
        if ((x = find(x)) != (y = find(y))) {
            if (parent[y] < parent[x]) swap(x, y);
            parent[x] += parent[y];
            parent[y] = x;
            --sz;
            return true;
        }
        return false;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int find(int x) { return parent[x] < 0 ? x : parent[x] = find(parent[x]); }
    int size(int x) { return -parent[find(x)]; }
    int size() { return sz; }
};

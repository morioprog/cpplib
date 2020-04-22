#define IGNORE

// #define PROBLEM "https://atcoder.jp/contests/abc106/tasks/abc106_d"

// #include "../../template/main.hpp"
// #include "../../datastructure/cumulativesum/cumulativesum2d.hpp"

signed main() {
 
    int N, M, Q;
    cin >> N >> M >> Q;
 
    vector<vector<int>> v(N + 1, vector<int>(N + 1, 0));
    while (M--) {
        int L, R;
        cin >> L >> R;
        v[L][R]++;
    }
 
    CumulativeSum2D<int> acc(v);
 
    while (Q--) {
        int p, q;
        cin >> p >> q;
        print(acc.query(p, p, q + 1, q + 1));
    }
 
}

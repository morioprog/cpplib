#define IGNORE

// @note uf.size()のverify (UnionFind)

// #define PROBLEM "https://atcoder.jp/contests/abc106/tasks/abc106_d"

// #include "../../template/main.hpp"
// #include "../../datastructure/unionfind/unionfind.hpp"

signed main() {

    int N, M, K;
    cin >> N >> M >> K;

    UnionFind uf(N);

    vector<vector<int>> frd(N);

    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        --A, --B;
        frd[A].emplace_back(B);
        frd[B].emplace_back(A);
        uf.unite(A, B);
    }

    vector<int> res(N);
    for (int i = 0; i < N; ++i) res[i] = uf.size(i);
    for (int i = 0; i < N; ++i) res[i] -= frd[i].size() + 1;
    for (int i = 0; i < K; ++i) {
        int A, B;
        cin >> A >> B;
        --A, --B;
        if (uf.same(A, B)) {
            res[A]--;
            res[B]--;
        }
    }

    for (int i = 0; i < N; ++i) cout << res[i] << " \n"[i == N - 1];

}

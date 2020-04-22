#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../template/main.hpp"
#include "../../datastructure/sparsetable.hpp"

signed main() {

    int N, Q;
    cin >> N >> Q;

    using T = long long;
    vector<T> A(N);
    for (auto& e: A) cin >> e;

    SparseTable<T> st(A, [](T a, T b) { return min(a, b); });

    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << endl;
    }

}

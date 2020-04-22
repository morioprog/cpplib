#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../../template/main.hpp"
#include "../../datastructure/cumulativesum/cumulativesum.hpp"

signed main() {

    int N, Q;
    cin >> N >> Q;

    using T = long long;
    vector<T> A(N);
    for (auto& e: A) cin >> e;

    CumulativeSum<T> acc(A);

    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << acc.query(l, r) << endl;
    }

}

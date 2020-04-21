#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"

#include "../../template/short.hpp"
#include "../../math/prime/prime_factor.hpp"

signed main() {

    int N;  cin >> N;
    auto pf = prime_factor(N);

    vector<int> res;
    for (auto& e: pf) {
        for (int i = 0; i < e.second; ++i) {
            res.emplace_back(e.first);
        }
    }

    cout << N << ": ";
    int sz = res.size();
    for (int i = 0; i < sz; ++i) {
        cout << res[i] << " \n"[i == sz - 1];
    }

}

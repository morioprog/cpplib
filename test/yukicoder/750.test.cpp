#define PROBLEM "https://yukicoder.me/problems/no/750"

#include "../../template/main.hpp"
#include "../../math/fraction.hpp"

signed main() {

    int N;
    cin >> N;

    using F = Fraction<int>;
    vector<pair<F, pair<int, int>>> v;
    while (N--) {
        int A, B;
        cin >> A >> B;
        v.emplace_back(make_pair(F(A, B), make_pair(A, B)));
    }
    sort(v.rbegin(), v.rend());

    for (auto &[_, f] : v) {
        cout << f.first << ' ' << f.second << endl;
    }

}

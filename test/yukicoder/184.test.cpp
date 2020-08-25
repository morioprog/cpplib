#define PROBLEM "https://yukicoder.me/problems/no/184"

#include "../../template/main.hpp"
#include "../../math/matrix/xorvector.hpp"

signed main() {

    int N;
    cin >> N;
    vector<ll> A(N);
    for (auto &e : A) cin >> e;

    XorVector mat(N);
    for (auto &e : A) mat.emplace(e);
    mat.gaussian_elimination();

    cout << (1LL << mat.rank) << endl;

}

#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include "../../template/main.hpp"
#include "../../math/extgcd.hpp"

signed main() {

    long long A, B, X, Y;
    cin >> A >> B;
    extgcd(A, B, X, Y);
    cout << X << ' ' << Y << endl;

}

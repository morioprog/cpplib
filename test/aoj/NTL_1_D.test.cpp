#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D"

#include "../../template/short.hpp"
#include "../../math/prime/euler_totient.hpp"

signed main() {

    int N;  cin >> N;
    cout << euler_totient(N) << endl;

}

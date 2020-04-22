#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"

#include "../../template/main.hpp"
#include "../../math/modint.hpp"

signed main() {

    int M, N;   cin >> M >> N;
    cout << (modint(M) ^ N) << endl;

}

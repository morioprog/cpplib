#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C"

#include "../../template/main.hpp"
#include "../../math/prime/eratosthenes.hpp"

const int MX = 100000010;

signed main() {

    auto prime_table = eratosthenes(MX);

    int N;
    cin >> N;

    int res = 0;
    while (N--) {
        int X;
        cin >> X;
        res += prime_table[X];
    }
    cout << res << endl;

}

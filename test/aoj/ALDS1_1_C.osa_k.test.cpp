#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C"

#include "../../template/main.hpp"
#include "../../math/prime/osa_k.hpp"

const int MX = 100000010;

signed main() {

    osa_k pm(MX);

    int N;
    cin >> N;

    int res = 0;
    while (N--) {
        int X;
        cin >> X;
        res += pm.is_prime(X);
    }
    cout << res << endl;

}

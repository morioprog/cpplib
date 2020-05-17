#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_C"

#include "../../template/main.hpp"
#include "../../math/prime/is_prime.hpp"

signed main() {

    int N;
    cin >> N;

    int res = 0;
    while (N--) {
        int X;
        cin >> X;
        res += is_prime(X);
    }

    cout << res << endl;

}

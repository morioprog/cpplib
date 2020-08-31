#define PROBLEM "https://yukicoder.me/problems/no/888"

#include "../../template/main.hpp"
#include "../../math/prime/divisor.hpp"

signed main() {
    ll N, res = 0;
    cin >> N;
    for (auto d : divisor(N)) res += d;
    cout << res << endl;
}

#define PROBLEM "https://yukicoder.me/problems/no/649"

#include "../../template/main.hpp"
#include "../../datastructure/lrprique.hpp"

signed main() {

    int Q, K;
    cin >> Q >> K;

    LRPrique<ll> lr([=](int sz) -> int { return K; });

    while (Q--) {
        int T;
        cin >> T;
        if (T == 1) {
            ll a;
            cin >> a;
            lr.emplace(a);
        } else {
            ll ret = lr.get();
            if (ret == lr.err) {
                cout << -1 << endl;
            } else {
                cout << ret << endl;
                lr.L_pop();
            }
        }
    }

}

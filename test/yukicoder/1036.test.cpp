#define PROBLEM "https://yukicoder.me/problems/no/1036"

#include "../../template/main.hpp"
#include "../../datastructure/queueaggregation.hpp"

signed main() {

    int N;
    cin >> N;

    vector<ll> A(N);
    for (auto &e : A) cin >> e;
    A.emplace_back(1LL);

    ll res = 0;
    QueueAggregation<ll> swag([](ll a, ll b) { return gcd(a, b); }, 0LL);
    swag.emplace(A.front());

    int r = 0;
    for (int l = 0; l < N; ++l) {
        while (swag.query() != 1LL) swag.emplace(A[++r]);
        res += N - r;
        if (l == r) swag.emplace(A[++r]);
        swag.pop();
    }
    cout << res << endl;

}

#define PROBLEM "https://yukicoder.me/problems/no/1183"

#include "../../template/main.hpp"
#include "../../util/groupby.hpp"

signed main() {

    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for (auto &e : A) cin >> e;
    for (auto &e : B) cin >> e;
    for (int i = 0; i < N; ++i) C[i] = A[i] == B[i];

    int res = 0;
    for (auto &[k, v] : groupby(C)) res += k == 0;
    cout << res << endl;
    
}

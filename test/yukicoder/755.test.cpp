#define PROBLEM "https://yukicoder.me/problems/no/755"

#include "../../template/main.hpp"
#include "../../datastructure/cumulativesum/cumulativesum2d.hpp"

signed main() {

    int N, M;
    cin >> N >> M;

    vector<vector<long long>> A(M, vector<long long>(M, 0LL));
    for (auto &v : A)
        for (auto &e : v) cin >> e;

    CumulativeSum2D<long long> acc(A);

    while (N--) {
        int X, Y;
        cin >> X >> Y;
        --X, --Y;
        int res = 0;
        for (int a = 0; a <= X; ++a) {
            for (int b = X + 1; b <= M; ++b) {
                for (int c = 0; c <= Y; ++c) {
                    for (int d = Y + 1; d <= M; ++d) {
                        if (acc.query(a, c, b, d) == 0) ++res;
                    }
                }
            }
        }
        cout << res << endl;
    }

}

#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_D"

#include "../../template/main.hpp"
#include "../../util/dice.hpp"

signed main() {

    int N;
    cin >> N;
    vector<vector<int>> labels(N, vector<int>(6));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 6; ++j) cin >> labels[i][j];

    Dice dc1(1, 2), dc2(1, 2);

    auto same = [&](int idx1, int idx2) {
        for (int i = 0; i < 6; ++i)
            if (labels[idx1][dc1.get(i) - 1] != labels[idx2][dc2.get(i) - 1]) return false;
        return true;
    };

    auto check = [&](int idx1, int idx2) -> bool {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 4; ++j) {
                dc2.rot(R);
                if (same(idx1, idx2)) return true;
            }
            if (i == 3) dc2.rot(R);
            if (i == 4) dc2.rot(D);
            dc2.rot(D);
        }
        return false;
    };

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (check(i, j)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

}

#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_C"

#include "../../template/main.hpp"
#include "../../util/dice.hpp"

signed main() {

    vector<int> label1(6), label2(6);
    for (int i = 0; i < 6; ++i) cin >> label1[i];
    for (int i = 0; i < 6; ++i) cin >> label2[i];

    Dice dc1(1, 2), dc2(1, 2);
    auto same = [&]() {
        for (int i = 0; i < 6; ++i) {
            if (label1[dc1.get(i) - 1] != label2[dc2.get(i) - 1]) return false;
        }
        return true;
    };

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 4; ++j) {
            dc2.rot(R);
            if (same()) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        if (i == 3) dc2.rot(R);
        if (i == 4) dc2.rot(D);
        dc2.rot(D);
    }

    cout << "No" << endl;

}

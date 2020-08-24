#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_A"

#include "../../template/main.hpp"
#include "../../util/dice.hpp"

signed main() {

    vector<int> label(6);
    for (int i = 0; i < 6; ++i) cin >> label[i];

    Dice dc(1, 2);
    string manip;   cin >> manip;
    for (auto& c: manip) {
        if (c == 'N') dc.rot(U);
        if (c == 'E') dc.rot(R);
        if (c == 'W') dc.rot(L);
        if (c == 'S') dc.rot(D);
    }

    cout << label[dc.T - 1] << endl;

}

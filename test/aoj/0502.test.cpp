#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0502"

#include "../../template/main.hpp"
#include "../../util/dice.hpp"

signed main() {

    int N;
    while (cin >> N, N) {
        Dice dc(1, 2);
        int res = 1;
        while (N--) {
            string S;
            cin >> S;
            if (S[0] == 'N') dc.rot(U);
            if (S[0] == 'E') dc.rot(R);
            if (S[0] == 'W') dc.rot(L);
            if (S[0] == 'S') dc.rot(D);
            if (S[0] == 'R') dc.rot(L), dc.rot(D), dc.rot(R);
            if (S[0] == 'L') dc.rot(R), dc.rot(D), dc.rot(L);
            res += dc.T;
        }
        cout << res << endl;
    }

}

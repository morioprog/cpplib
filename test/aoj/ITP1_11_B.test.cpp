#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_B"

#include "../../template/main.hpp"
#include "../../util/dice.hpp"

signed main() {

    vector<int> label(6);
    map<int, int> rev;
    for (int i = 0; i < 6; ++i) {
        cin >> label[i];
        rev[label[i]] = i + 1;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int T, S;
        cin >> T >> S;
        T = rev[T];
        S = rev[S];
        Dice dc(T, S);
        cout << label[dc.E - 1] << endl;
    }

}

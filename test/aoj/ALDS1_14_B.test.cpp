#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"

#include "../../template/main.hpp"
#include "../../string/rollinghash.hpp"

signed main() {

    string S, T;
    cin >> S >> T;

    int S_sz = S.size();
    int T_sz = T.size();

    RH rh_S(init(S)), rh_T(init(T));

    for (int i = 0; i <= S_sz - T_sz; ++i) {
        if (get(rh_S, i, i + T_sz) == get(rh_T, 0, T_sz)) {
            cout << i << endl;
        }
    }

}

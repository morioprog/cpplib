#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_D"

#include "../../template/main.hpp"
#include "../../string/suffixarray.hpp"

signed main() {

    string s;
    cin >> s;
    SuffixArray sa(s);

    int Q;
    cin >> Q;
    while (Q--) {
        string t;
        cin >> t;
        auto rng = sa.lower_upper_bound(t);
        cout << (rng.first != rng.second) << endl;
    }

}

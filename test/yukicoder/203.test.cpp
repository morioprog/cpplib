#define PROBLEM "https://yukicoder.me/problems/no/203"

#include "../../template/main.hpp"
#include "../../util/groupby.hpp"

signed main() {

    string s, t;
    cin >> s >> t;
    s += t;

    int res = 0;
    for (auto &[k, v] : groupby(s))
        if (k == 'o' and res < v) res = v;
    cout << res << endl;
    
}

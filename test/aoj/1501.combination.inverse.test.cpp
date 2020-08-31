#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1501"

#include "../../template/main.hpp"
#include "../../math/modint.hpp"
#include "../../math/combination/inverse.hpp"

using mint = ModInt<(int)1e8 + 7>;
Combination<mint> comb(4020);

signed main() {
    int R, C, a1, a2, b1, b2;
    cin >> R >> C >> a1 >> a2 >> b1 >> b2;
    map<int, mint> mp;
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            int c1  = b1 + dr * R;
            int c2  = b2 + dc * C;
            int dst = abs(a1 - c1) + abs(a2 - c2);
            mp[dst] += comb.C(dst, abs(a1 - c1));
        }
    }
    cout << mp.begin()->second << endl;
}

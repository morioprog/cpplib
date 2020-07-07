#define PROBLEM "https://yukicoder.me/problems/no/117"

#include "../../template/main.hpp"
#include "../../math/modint.hpp"
#include "../../math/combination/inverse.hpp"

signed main() {

    Combination<modint> comb;

    int Q;
    scanf("%d\n", &Q);

    while (Q--) {
        int N, K; char c;
        scanf("%c(%d,%d)\n", &c, &N, &K);
        if (c == 'C') printf("%lld\n", comb.C(N, K).x);
        if (c == 'P') printf("%lld\n", comb.P(N, K).x);
        if (c == 'H') printf("%lld\n", comb.H(N, K).x);
    }

}

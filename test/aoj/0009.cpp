#define IGNORE

// #define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009"

// #include "../../template/main.hpp"
// #include "../../math/prime/eratosthenes.hpp"

const int MX = 1000010;

signed main() {

    auto prime_table = eratosthenes(MX);
    vector<int> acc(MX + 1, 0);
    for (int i = 0; i < MX; ++i) acc[i + 1] = acc[i] + prime_table[i + 1];

    int N;
    while (cin >> N) cout << acc[N] << endl;

}

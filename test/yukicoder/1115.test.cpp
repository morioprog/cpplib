#define PROBLEM "https://yukicoder.me/problems/no/1115"

#include "../../template/main.hpp"
#include "../../datastructure/binaryindexedtree.hpp"
#include "../../util/inversionnumber.hpp"

signed main() {

    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for (auto &e : A) cin >> e;
    for (auto &e : B) cin >> e;

    map<int, int> mp;
    for (int i = 0; i < N; ++i) mp[B[i]] = i;
    for (int i = 0; i < N; ++i) C[i] = mp[A[i]];
    cout << inversion_number(C) << endl;

}

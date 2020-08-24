/**
* @brief エラトステネスの篩
* @docs docs/math/prime/eratosthenes.md
*/

vector<bool> eratosthenes(const int n) {
    vector<bool> r(n + 1, true);
    for (int i = 2; i * i <= n; ++i) {
        if (r[i]) {
            for (int j = i * 2; j <= n; j += i) r[j] = false;
        }
    }
    if (r.size() > 2) {
        r[0] = r[1] = false;
    } else if (r.size() > 1) {
        r[0] = false;
    }
    return r;
}

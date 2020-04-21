/**
 * @brief Divisor (約数)
 * @docs docs/math/prime/divisor.md
 */

vector<long long> divisor(const long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.emplace_back(i);
            if (i * i != n) ret.emplace_back(n / i);
        }
    }
    return ret;
}

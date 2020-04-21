/**
 * @brief Prime Factor (素因数分解)
 * @docs docs/math/prime/prime_factor.md
 */

map<long long, int> prime_factor(long long n) {
    map<long long, int> ret;
    for (long long i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ++ret[i];
            n /= i;
        }
    }
    if (n != 1) ret[n] = 1;
    return ret;
}

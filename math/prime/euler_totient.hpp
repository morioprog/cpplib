/**
* @brief Euler's totient function (オイラーのφ関数)
* @docs docs/math/prime/euler_totient.md
*/

long long euler_totient(long long n) {
    long long ret = n;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i) continue;
        ret -= ret / i;
        while (n % i == 0) n /= i;
    }
    if (n > 1) ret -= ret / n;
    return ret;
}

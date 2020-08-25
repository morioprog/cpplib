/**
 * @brief 素数判定
 * @docs docs/math/prime/is_prime.md
 */

bool is_prime(long long n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

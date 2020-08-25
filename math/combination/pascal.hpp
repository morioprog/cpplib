/**
 * @brief Combination (Pascal)
 * @docs docs/math/combination/pascal.md
 */

template <typename T>
T C_pascal(long long n, int r) {
    if (r == 0) return T(1);
    if (r < 0) return T(0);
    if (n < 0) return T(r & 1 ? -1 : 1) * C_pascal<T>(-n + r - 1, r);
    if (n == 0 || n < r) return T(0);
    T ret(1);
    for (int i = 1; i <= r; ++i) ret *= n--, ret /= i;
    return ret;
}

template <typename T>
T P_pascal(long long n, int r) {
    if (n < r || r < 0) return T(0);
    T ret(1);
    for (int i = 1; i <= r; ++i) ret *= n--;
    return ret;
}

template <typename T>
T H_pascal(long long n, int r) {
    if (n < 0 || r < 0) return T(0);
    if (!n && !r) return T(1);
    return C_pascal<T>(n + r - 1, r);
}

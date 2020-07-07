/**
 * @brief Combination (Inverse)
 * @docs docs/math/combination/inverse.md
 */

template<typename T>
struct Combination {
    using u32 = unsigned int;
    using i64 = long long;
    Combination() {}
    Combination(u32 n) { init(n); }
    vector<T> fact, finv, invs;
    void init(u32 n) {
        u32 m = fact.size();
        if (n < m) return;
        fact.resize(n + 1, 1);
        finv.resize(n + 1, 1);
        invs.resize(n + 1, 1);
        if (m == 0) m = 1;
        for (u32 i = m; i <= n; ++i) fact[i] = fact[i - 1] * T(i);
        finv[n] = T(1) / fact[n];
        for (u32 i = n; i >= m; --i) finv[i - 1] = finv[i] * T(i);
        for (u32 i = m; i <= n; ++i) invs[i] = finv[i] * fact[i - 1];
    }
    T getFact(u32 n) { init(n); return fact[n]; }
    T getFinv(u32 n) { init(n); return finv[n]; }
    T getInvs(u32 n) { init(n); return invs[n]; }
    T C(i64 n, i64 r) {
        if (r == 0) return T(1);
        if (r <  0) return T(0);
        if (n <  0) return T(r & 1 ? -1 : 1) * C(-n + r - 1, r);
        if (n == 0 || n < r) return T(0);
        init(n);
        return fact[n] * finv[n - r] * finv[r];
    }
    T P(i64 n, i64 r) {
        if (n < r || r < 0) return T(0);
        init(n);
        return fact[n] * finv[n - r];
    }
    T H(i64 n, i64 r) {
        if (n < 0 || r < 0) return T(0);
        if (!n && !r) return T(1);
        init(n + r - 1);
        return C(n + r - 1, r);
    }
};

/**
 * @brief ModInt
 * @docs docs/math/modint.md
 */

template< int MODULO > struct ModInt {
    using i32 = int;
    using i64 = long long;
    using u32 = unsigned int;
    using u64 = unsigned long long;
    u64 x; ModInt() : x(0) {}
    ModInt(i64 y) : x(set(y % MODULO + MODULO)) {}
    static u64 set(const i64 &y) { return (y < MODULO) ? y : y - MODULO; }
    ModInt operator+(const ModInt &m) const { return ModInt(set(x + m.x)); }
    ModInt operator-(const ModInt &m) const { return ModInt(set(x + MODULO - m.x)); }
    ModInt operator*(const ModInt &m) const { return ModInt(x * m.x % MODULO); }
    ModInt operator/(const ModInt &m) const { return ModInt(x) * ~ModInt(m.x); }
    ModInt &operator+=(const ModInt &m) { return *this = *this + m; }
    ModInt &operator-=(const ModInt &m) { return *this = *this - m; }
    ModInt &operator*=(const ModInt &m) { return *this = *this * m; }
    ModInt &operator/=(const ModInt &m) { return *this = *this / m; }
    ModInt &operator^=(const u64 &y) { return *this = *this ^ y; }
    ModInt operator~ () const { return *this ^ (MODULO - 2); }
    ModInt operator- () const { return ModInt(set(MODULO - x)); }
    ModInt operator! () const { return getFact(u32(*this)); }
    ModInt operator& () const { return getFinv(u32(*this)); }
    ModInt operator++() { return *this = ModInt(set(x + 1)); }
    ModInt operator--() { return *this = ModInt(set(x + MODULO - 1)); }
    bool operator==(const ModInt &m) const { return x == m.x; }
    bool operator!=(const ModInt &m) const { return x != m.x; }
    bool operator< (const ModInt &m) const { return x <  m.x; }
    bool operator<=(const ModInt &m) const { return x <= m.x; }
    bool operator> (const ModInt &m) const { return x >  m.x; }
    bool operator>=(const ModInt &m) const { return x >= m.x; }
    explicit operator u64() const { return x; }
    ModInt operator^(i64 y) const { return pow(x, y); }
    static ModInt pow(i64 x, i64 y) {
        bool neg = false;
        if (y < 0) y = -y, neg = true;
        ModInt u(1), t(x);
        while (y) { if (y & 1) u *= t; t *= t; y >>= 1; }
        return neg ? ModInt(1) / u : u;
    }
    friend ostream &operator<<(ostream &os, const ModInt< MODULO > &m) { return os << m.x; }
    friend istream &operator>>(istream &is, ModInt< MODULO > &m) { u64 y; is >> y; m = ModInt(y); return is; }
    static vector< ModInt > fact, finv, invs;
    static void init(u32 n) {
        u32 m = fact.size();
        if (n < m) return;
        fact.resize(n + 1, 1);
        finv.resize(n + 1, 1);
        invs.resize(n + 1, 1);
        if (m == 0) m = 1;
        for (u32 i = m; i <= n; ++i) fact[i] = fact[i - 1] * ModInt(i);
        finv[n] = ModInt(1) / fact[n];
        for (u32 i = n; i >= m; --i) finv[i - 1] = finv[i] * ModInt(i);
        for (u32 i = m; i <= n; ++i) invs[i] = finv[i] * fact[i - 1];
    }
    static ModInt getFact(u32 n) { init(n); return fact[n]; }
    static ModInt getFinv(u32 n) { init(n); return finv[n]; }
    static ModInt getInvs(u32 n) { init(n); return invs[n]; }
    static ModInt C(i64 n, i64 r) {
        if (r == 0) return ModInt(1);
        if (r <  0) return ModInt(0);
        if (n <  0) return ModInt(r & 1 ? MODULO - 1 : 1) * C(-n + r - 1, r);
        if (n == 0 || n < r) return ModInt(0);
        init(n);
        return fact[n] * finv[n - r] * finv[r];
    }
    static ModInt P(i64 n, i64 r) {
        if (n < r || r < 0) return ModInt(0);
        init(n);
        return fact[n] * finv[n - r];
    }
    static ModInt H(i64 n, i64 r) {
        if (n < 0 || r < 0) return ModInt(0);
        if (!n && !r) return ModInt(1);
        init(n + r - 1);
        return C(n + r - 1, r);
    }
    static ModInt montmort(u32 n) {
        ModInt res;
        init(n);
        for (u32 k = 2; k <= n; ++k) {
            if (k & 1) res -= finv[k];
            else res += finv[k];
        }
        return res *= fact[n];
    }
    static ModInt LagrangePolynomial(vector<ModInt> &y, i64 t) {
        u32 n = y.size() - 1;
        if (t <= n) return y[t];
        init(n + 1);
        ModInt res, num(1);
        for (int i = 0; i <= n; ++i) num *= ModInt(t - i);
        for (int i = 0; i <= n; ++i) {
            ModInt tmp = y[i] * num / (ModInt(t - i)) * finv[i] * finv[n - i];
            if ((n - i) & 1) res -= tmp;
            else res += tmp;
        }
        return res;
    }
};
template< int MODULO > vector<ModInt< MODULO >> ModInt< MODULO >::fact = vector<ModInt< MODULO >>();
template< int MODULO > vector<ModInt< MODULO >> ModInt< MODULO >::finv = vector<ModInt< MODULO >>();
template< int MODULO > vector<ModInt< MODULO >> ModInt< MODULO >::invs = vector<ModInt< MODULO >>();
constexpr int MODULO = (int)1e9 + 7;
using modint = ModInt< MODULO >;

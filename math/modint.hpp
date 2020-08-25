/**
 * @brief ModInt
 * @docs docs/math/modint.md
 */

template <int MODULO>
struct ModInt {
    using i32 = int;
    using i64 = long long;
    using u32 = unsigned int;
    using u64 = unsigned long long;
    u64 x;
    ModInt()
        : x(0) {}
    ModInt(i64 y)
        : x(set(y % MODULO + MODULO)) {}
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
    ModInt operator~() const { return *this ^ (MODULO - 2); }
    ModInt operator-() const { return ModInt(set(MODULO - x)); }
    ModInt operator++() { return *this = ModInt(set(x + 1)); }
    ModInt operator--() { return *this = ModInt(set(x + MODULO - 1)); }
    bool operator<(const ModInt &m) const { return x < m.x; }
    bool operator>(const ModInt &m) const { return x > m.x; }
    bool operator==(const ModInt &m) const { return x == m.x; }
    bool operator!=(const ModInt &m) const { return x != m.x; }
    bool operator<=(const ModInt &m) const { return x <= m.x; }
    bool operator>=(const ModInt &m) const { return x >= m.x; }
    explicit operator u64() const { return x; }
    ModInt operator^(i64 y) const { return pow(x, y); }
    static ModInt pow(i64 x, i64 y) {
        bool neg = false;
        if (y < 0) y = -y, neg = true;
        ModInt u(1), t(x);
        while (y) {
            if (y & 1) u *= t;
            t *= t;
            y >>= 1;
        }
        return neg ? ModInt(1) / u : u;
    }
    friend ostream &operator<<(ostream &os, const ModInt<MODULO> &m) { return os << m.x; }
    friend istream &operator>>(istream &is, ModInt<MODULO> &m) {
        u64 y;
        is >> y;
        m = ModInt(y);
        return is;
    }
};
constexpr int MODULO = (int)1e9 + 7;
using modint         = ModInt<MODULO>;

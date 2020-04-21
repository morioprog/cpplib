/**
 * @brief Fraction (分数)
 * @docs docs/math/fraction.md
 */

struct Fraction {
    using T = long long;
    T numer, denom;
    T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
    Fraction(T n = 0, T d = 1) {
        T g = gcd(n, d);
        assert(d != 0);
        numer = n / g, denom = d / g;
        if (denom < 0) numer *= -1, denom *= -1;
    }
    Fraction operator+(const Fraction &f) const { return Fraction(numer * f.denom + denom * f.numer, denom * f.denom); }
    Fraction operator-(const Fraction &f) const { return Fraction(numer * f.denom - denom * f.numer, denom * f.denom); }
    Fraction operator*(const Fraction &f) const { return Fraction(numer * f.numer, denom * f.denom); }
    Fraction operator/(const Fraction &f) const { return Fraction(numer * f.denom, denom * f.numer); }
    Fraction &operator+=(const Fraction &f) { return *this = *this + f; }
    Fraction &operator-=(const Fraction &f) { return *this = *this - f; }
    Fraction &operator*=(const Fraction &f) { return *this = *this * f; }
    Fraction &operator/=(const Fraction &f) { return *this = *this / f; }
    Fraction operator~() const { return Fraction(denom, numer); }
    bool operator==(const Fraction &f) const { return numer == f.numer and denom == f.denom; }
    bool operator!=(const Fraction &f) const { return numer != f.numer  or denom != f.denom; }
    bool operator< (const Fraction &f) const { return numer * f.denom <  f.numer * denom; }
    bool operator<=(const Fraction &f) const { return numer * f.denom <= f.numer * denom; }
    bool operator> (const Fraction &f) const { return numer * f.denom >  f.numer * denom; }
    bool operator>=(const Fraction &f) const { return numer * f.denom >= f.numer * denom; }
    double to_double() const { return (double) numer / denom; }
    friend ostream &operator<<(ostream &os, const Fraction &f) { return os << f.numer << " / " << f.denom; }
};
